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

vector<int> parent;

bool sortbyfirst(const pair<int,int> &a, const pair<int,int> &b) 
{ 
    return (a.first > b.first); 
}

void    init(int n)
{
    parent.resize(n + 1);

    for (int i = 0; i <= n; i++)
        parent[i] = i;
}

int     find(int x)
{
    if (x == parent[x])
        return x;
    return (parent[x] = find(parent[x]));
}

void    merge(int x, int y)
{
    x = find(x);
    y = find(y);
    
    parent[x] = y;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    vector<ii> edge(m);
    vector<ii> cost(m);
    
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edge[i].xx, &edge[i].yy, &cost[i].xx);
        cost[i].yy = i;
    }
    
    sort(all(cost), sortbyfirst);
    
    init(n);
    i64 ans = 0;
    int count = 0;
    for (int i = 0; i < m; i++) {
        int idx = cost[i].yy;
        
        if (find(edge[idx].xx) == find(edge[idx].yy))
            continue;
        ans += cost[i].xx;
        merge(edge[idx].xx, edge[idx].yy);
        count++;
    }
    
    if (count != n - 1) {
        cout << -1 << endl;
        return 0;
    }
    
    cout << ans << endl;
    return 0;
}