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

int maps[305][305];
bool visited[305][305];
int h[305][305];

int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[] = { 2, 1, -1, -2, -2, -1, 1, 2 };


void solve()
{
    int l, startX, startY, endX, endY;
    scanf("%d %d %d %d %d", &l, &startX, &startY, &endX, &endY);

    memset(maps, 0, sizeof(maps));
    memset(visited, false, sizeof(visited));
    memset(h, 0, sizeof(h));

    queue<ii> Q;
    Q.emplace(startX, startY);
    visited[startX][startY] = true;

    int ans = 0;
    while (!Q.empty())
    {
        ii curr = Q.front();
        Q.pop();

        //printf("%d %d\n", curr.xx, curr.yy);

        if (curr.xx == endX && curr.yy == endY)
        {
            ans = h[curr.xx][curr.yy];
            break;
        }
        
        for (int i = 0; i < 8; i++)
        {
            ii next;
            next.xx = curr.xx + dx[i];
            next.yy = curr.yy + dy[i];

            if (next.xx < 0 || l <= next.xx)
                continue;
            if (next.yy < 0 || l <= next.yy)
                continue;

            if (visited[next.xx][next.yy])
                continue;

            visited[next.xx][next.yy] = true;
            h[next.xx][next.yy] = h[curr.xx][curr.yy] + 1;
            Q.emplace(next.xx, next.yy);
        }
    }

    printf("%d\n", ans);
}
int main() 
{
    int t;
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++) {
        solve();
    }
    
    return 0;
}