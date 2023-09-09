#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <bitset>
#include <stdio.h>
#include <math.h>
#include <sstream>
#include<cassert>
#include <climits>
#include <tuple>

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()
#define MAXV 987654321
#define FOR(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

vector<int> parent;
int height[1005][1005];
int counts[1005][1005];
bool water[1005][1005];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int N, M;

int to_number(int i, int j) {
    return i * M + j;
}

int to_i(int x) {
    return x / M;
}

int to_j(int x) {
    return x % M;
}

void    init(int n)
{
    parent.resize(n + 1);

    for (int i = 0; i <= n; i++)
        parent[i] = i;
}

int     find(int x)
{
    if (x == parent[x])
        return x;
    return (parent[x] = find(parent[x]));
}

void    merge(int x, int y)
{
   int px = find(x);
   int py = find(y);

   int xi = to_i(px);
   int xj = to_j(px);
   int yi = to_i(py);
   int yj = to_j(py);

   if (height[xi][xj] < height[yi][yj]) {
        parent[py] = px;
   } else if (height[xi][xj] > height[yi][yj]) {
        parent[px] = py;
   } else {
       if (counts[xi][xj] < counts[yi][yj]) {
            parent[py] = px;
       } else {
            parent[px] = py;
       }
   }
}

void solve(int num) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    a--; b--;
    height[a][b] -= c;
    water[a][b] = true;
    counts[a][b] = num;

    FOR(i, 4) {
        int x = dx[i] + a;
        int y = dy[i] + b;

        if (x < 0 || N <= x) continue;
        if (y < 0 || M <= y) continue;
        if (!water[x][y]) continue;


        if (find(to_number(a, b)) != find(to_number(x, y))) {
            merge(to_number(a, b), to_number(x, y));
            continue;
        }

        // 같은 집합이라면
        if (height[a][b] < height[x][y]) {
            parent[to_number(a, b)] = to_number(a, b);
            merge(to_number(a, b), to_number(x, y));
        } else { // 높이가 같다면
            if (counts[a][b] < counts[x][y]) {
                parent[to_number(a, b)] = to_number(a, b);
                merge(to_number(a, b), to_number(x, y));
            }
        }

        // merge(to_number(a, b), to_number(x, y));
    }

    int f = find(to_number(a, b));
    printf("%d %d\n", to_i(f)+1, to_j(f)+1);
}

int main() {
    int q;
    scanf("%d %d %d", &N, &M, &q);

    FOR(i, N) {
        FOR(j, M) {
            scanf("%d", &height[i][j]);
        }
    }

    init(N*M);

    FOR(i, q) {
        solve(i+1);
        // FOR(i, N*M) printf("%d ", parent[i]);
        // printf("\n");
    }

    return 0;
}
