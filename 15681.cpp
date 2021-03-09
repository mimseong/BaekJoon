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

vector<int> adj[100005];
int dp[100005];
bool visited[100005];
int heightSum = 0;

int dfs(int curr)
{
    heightSum++;
    visited[curr] = true;
    
    if (dp[curr] != 0)
        return dp[curr];

    for (int next : adj[curr])
    {
        if (!visited[next])
        {
            dp[curr] += dfs(next);
        }
    }
    dp[curr]++;
    return dp[curr];
}

int     main()
{
    int n, r, q;
    scanf("%d %d %d", &n, &r, &q);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    
    memset(visited, false, sizeof(visited));
    dfs(r);
    
    for (int i = 0; i < q; i++)
    {
        int in;
        scanf("%d", &in);
        printf("%d\n", dp[in]);
    }

    

    return 0;
}