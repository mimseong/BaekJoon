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
    x = find(x);
    y = find(y);

    parent[x] = y;
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);

    init(n);

    FOR(i, k) {
        int a, b;
        scanf("%d %d", &a, &b);
        merge(a, b);
    }

    int m;
    scanf("%d", &m);
    FOR(i, m) {
        int a, b;
        scanf("%d %d", &a, &b);

        if (find(a) == find(b)) {
            printf("1\n");
        }
        else {
            printf("0\n");
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);

	FOR(i, t){
	    printf("Scenario %d:\n", i+1);
	    solve();
	    printf("\n");
	}

	return 0;
}
