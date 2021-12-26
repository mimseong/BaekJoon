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
#include <stdio.h>
#include <math.h>
#include <sstream>

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

bool visited[100005];
vector <int> adj[100005];
int parent[100005];

void dfs(int curr)
{
    visited[curr] = true;
    
    for (int next : adj[curr])
    {
        if (visited[next])
            continue;
        parent[next] = curr;
        dfs(next);
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
    
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    
    memset(visited, false, sizeof(visited));
    dfs(1);

    for (int i = 2; i <= n; i++) {
        printf("%d\n", parent[i]);
    }
    
    return 0;
}