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

int v[1005][1005];
bool visited[1005][1005][2];
int h[1005][1005][2];

int n, m;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

struct maze {
    int x, y, z;
};

int     main()
{
    int sx, sy, ex, ey;

    cin >> n >> m >> sx >> sy >> ex >> ey;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> v[i][j];
        }
    }

    queue<maze> Q;
    Q.push({ sx, sy, 0 });
    visited[sx][sy][0] = true;

    int ans = -1;
    while (!Q.empty())
    {
        maze curr = Q.front();
        Q.pop();

        if (curr.x == ex && curr.y == ey)
        {
            ans = h[curr.x][curr.y][curr.z];
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            maze next;
            next.x = curr.x + dx[i];
            next.y = curr.y + dy[i];
            next.z = curr.z;

            if (next.x <= 0 || n < next.x)
                continue;
            if (next.y <= 0 || m < next.y)
                continue;

            if (v[next.x][next.y] == 1)
            {
                if (next.z == 1)
                    continue;
                else
                    next.z = 1;
            }

            if (visited[next.x][next.y][next.z] == false)
            {
                visited[next.x][next.y][next.z] = true;
                h[next.x][next.y][next.z] = h[curr.x][curr.y][curr.z] + 1;
                Q.push({ next.x, next.y, next.z });
            }
        }
    }

    cout << ans;

    return 0;
}