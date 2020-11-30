#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <bitset>

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

int dist[1005][1005][2];
int wall[1005][1005];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int     main()
{
    int n, m;
    cin >> n >> m;

    memset(dist, -1, sizeof(dist));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%1d", &wall[i][j]);

    queue<iii> q;
    q.emplace(1, 1, 0);
    dist[1][1][0] = 1;

    while (!q.empty())
    {
        auto [x, y, t] = q.front();
        q.pop();

        if (x == n && y == m)
        {
            printf("%d\n", dist[x][y][t]);
            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 1 || nx > n || ny < 1 || ny > m)
                continue;

            int nt = t;
            if (wall[nx][ny] == 1)
                nt++;

            if (nt >= 2 || dist[nx][ny][nt] != -1)
                continue;

            dist[nx][ny][nt] = dist[x][y][t] + 1;
            q.emplace(nx, ny, nt);
        }
    }

    printf("-1\n");

    return 0;
}