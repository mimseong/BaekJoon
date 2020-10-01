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

bool visited[500005];
vector<int> adj[500005];

int ans;

void dfs(int curr, int height)
{
    visited[curr] = true;

    bool isLeaf = true;
    for (int next : adj[curr])
    {
        if (!visited[next])
        {
            isLeaf = false;
            dfs(next, height + 1);
        }
    }
    if (isLeaf)
        ans += height;
}

int     main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

 /*   cout << ans << endl;*/

    if (ans % 2 == 0)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;

    return 0;
}