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

bool visited[505][505];
char maps[505][505];
int h[505][505];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int n, m, a, b, endx, endy;

bool    check_square(int x, int y)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (maps[x + i][y + j] == '.')
                return true;
        }
    }
    return false;
}

int     main()
{
    int k;
    scanf("%d %d %d %d %d", &n, &m, &a, &b, &k);
    n++, m++;

    for (int i = 0; i < k; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        maps[x][y] = '.';
    }

    int startx, starty;
    scanf("%d %d", &startx, &starty);
    scanf("%d %d", &endx, &endy);

    queue<ii> Q;
    Q.emplace(startx, starty);
    visited[startx][starty] = true;

    int ans = -1;
    while (!Q.empty())
    {
        ii curr = Q.front();
        Q.pop();

        //printf("%d %d\n", curr.xx, curr.yy);

        if (curr.xx == endx && curr.yy == endy)
        {
            ans = h[curr.xx][curr.yy];
            break;
        }
        
        for (int i = 0; i < 4; i++)
        {
            ii next;
            next.xx = curr.xx + dx[i];
            next.yy = curr.yy + dy[i];

            if (next.xx <= 0 || n < next.xx + a)
                continue;
            if (next.yy <= 0 || m < next.yy + b)
                continue;

            if (visited[next.xx][next.yy])
                continue;

            if (check_square(next.xx, next.yy))
                continue;

            visited[next.xx][next.yy] = true;
            h[next.xx][next.yy] = h[curr.xx][curr.yy] + 1;
            Q.emplace(next.xx, next.yy);
        }
    }

    printf("%d\n", ans);

    return 0;
}