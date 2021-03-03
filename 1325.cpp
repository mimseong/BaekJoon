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
#include <cstring>
#define xx first
#define yy second
 
using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

bool visited[10005];
vector <int> adj[10005];

int    dfs(int curr) {
    visited[curr] = true;
    
    int sumv = 0;
    for (int next : adj[curr]) {
        if (visited[next])
            continue;
        sumv += dfs(next);
    }
    
    return sumv + 1;
}

int     main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[v].push_back(u);
    }
    
    vector<int> v(n + 5);
    for (int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        v[i] = dfs(i);
    }
    
    int maxv = v[1];
    for (int i = 1; i <= n; i++)
    {
        // printf("%d ", v[i]);
        maxv = max(maxv, v[i]);
    }
    // printf("\n");
    
    for (int i = 1; i <= n; i++) {
        if (v[i] == maxv)
            printf("%d ", i);
    }
    
    return 0;
}