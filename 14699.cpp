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

vector<int> adj[5005];
int         dp[5005];
int         height[5005];

int dfs(int curr)
{
    if (dp[curr] != 0)
        return dp[curr];

    for (int i = 0; i < adj[curr].size(); i++)
        dp[curr] = max(dp[curr], dfs(adj[curr][i]));
    return (++dp[curr]);
}

int     main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> height[i];

    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;

        if (height[x] < height[y])
            adj[x].push_back(y);
        else
            adj[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
        cout << dfs(i) << "\n";
    
    return 0;
}