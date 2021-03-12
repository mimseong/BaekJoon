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

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

vector<int> adj[500005];
bool visited[500005];
int heightSum = 0;

void dfs(int curr, int h)
{
    visited[curr] = true;

    bool leaf = true;
    for (int next : adj[curr])
    {
        if (!visited[next])
        {
            leaf = false;
            dfs(next, h + 1);
        }
    }
    if (leaf)
        heightSum += h;
}

int     main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    memset(visited, false, sizeof(visited));
    dfs(1, 0);

    if (heightSum % 2 == 0)
        printf("No\n");
    else
        printf("Yes\n");

    return 0;
}