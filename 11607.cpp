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

int n, m;
int mapv[505][505];
bool visited[505][505];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};


int main() {
    scanf("%d %d", &n, &m);


	FOR(i, n)
	    FOR(j, m)
	        scanf("%1d", &mapv[i][j]);

    memset(visited, false, sizeof(visited));

	queue<iii> Q;
    Q.emplace(0, 0, 0);
    visited[0][0] = true;

    int ans = -1;
    while (!Q.empty())
    {
        auto curr = Q.front();
        Q.pop();

        int x = get<0>(curr);
        int y = get<1>(curr);
        int hop = get<2>(curr);

        // printf("%d %d\n", x, y);

        if (x == n-1 && y == m-1)
        {
            ans = hop;
            break;
        }

        if (mapv[x][y] == 0)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + mapv[x][y] * dx[i];
            int ny = y + mapv[x][y] * dy[i];

            if (nx < 0 || n <= nx)
                continue;
            if (ny < 0 || m <= ny)
                continue;
            if (visited[nx][ny])
                continue;

            visited[nx][ny] = true;
            Q.emplace(nx, ny, hop+1);
        }
    }

	if (ans != -1) {
	    printf("%d\n", ans);
	} else {
	    printf("IMPOSSIBLE\n");
	}

	return 0;
}
