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

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()

using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

bool visited[255][255];
char maps[255][255];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int n, m;

void dfs(int x, int y, ii &res)
{
    if (visited[x][y] || maps[x][y] == '#')
        return ;

    visited[x][y] = true;
    if (maps[x][y] == 'v')
        res.yy++;
    else if (maps[x][y] == 'k')
        res.xx++;
    
    for (int i = 0; i < 4; i++)
    {
        if (x + dx[i] >= 0 && y + dy[i] >= 0 && y + dy[i] < m && x + dx[i] < n)
            dfs(x + dx[i], y + dy[i], res);
    }

}

int     main()
{
    scanf("%d %d", &n, &m);

    char tmp;
    scanf("%c", &tmp);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            scanf("%c", &maps[i][j]);
        scanf("%c", &tmp);
    }

    ii ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && maps[i][j] != '#')
            {
                ii res;
                res.xx = 0, res.yy = 0;
                dfs(i, j, res);
                
                if (res.xx > res.yy)
                    ans.xx += res.xx;
                else
                    ans.yy += res.yy;
            }
        }
    }

    printf("%d %d\n", ans.xx, ans.yy);

    return 0;
}