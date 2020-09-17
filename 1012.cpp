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

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()

using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int n, m;
int maps[55][55];
bool visited[55][55];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void dfs(int y, int x)
{
    visited[y][x] = true;

    for (int i = 0; i < 4; i++)
    {
        if (x + dx[i] < 0 || m <= x + dx[i])
            continue;
        if (y + dy[i] < 0 || n <= y + dy[i])
            continue;

        if (maps[y + dy[i]][x + dx[i]] == 0)
            continue;

        if (visited[y + dy[i]][x + dx[i]])
            continue;

        dfs(y + dy[i], x + dx[i]);
    }
}

void solve()
{
    int k;
    cin >> m >> n >> k;

    memset(maps, 0, sizeof(maps));
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        maps[y][x] = 1;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maps[i][j] == 0 || visited[i][j])
                continue;
            dfs(i, j);
            ans++;
        }
    }
    
    cout << ans << endl;
}

int     main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}