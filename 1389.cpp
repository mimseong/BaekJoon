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
#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()
 
using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;
 
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++)
    {
    	int u, v;
    	scanf("%d %d", &u, &v);
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    	sort(adj[i].begin(), adj[i].end());

    int min = 99999;
    int idx = -1;
    
    vector<bool> visited(n+1, false);
    vector<int> connect(n+1, 0);
    queue<int> q;
    
    for (int i = 1; i <= n; i++)
    {
        fill(all(visited), false);
        fill(all(connect), 0);
        
        q.push(i);
        visited[i] = true;
    
        while (!q.empty())
        {
        	int curr = q.front();
        	q.pop();
        	
        	for (int next : adj[curr])
        	{
        		if (!visited[next])
        		{
        			visited[next] = true;
        			connect[next] = connect[curr] + 1;
        			q.push(next);
        		}
        	}
        }
        
        int count = 0;
        for (int j = 1; j <= n; j++)
            count += connect[j];
        
        if (count < min)
        {
            min = count;
            idx = i;
        }
    }
    
    cout << idx;
    return 0;
}