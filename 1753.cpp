#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <cstring>
#include <map>
#define xx first
#define yy second
 
using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;


struct Edge
{
    Edge(int to_, int w_) : to(to_), w(w_) {}
    int to, w;
};

vector<Edge> edge[300005];
int dist[300005];
bool visited[300005];

void calc(int k, int v)
{
    memset(dist, -1, sizeof(dist));
    memset(visited, false, sizeof(visited));
    
    dist[k] = 0;
    
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    
    pq.emplace(0, k);
    
    while (!pq.empty())
    {
        auto now = pq.top();
        pq.pop();
        
        if (visited[now.yy])
            continue;
        
        visited[now.yy] = true;
        
        for (auto & e : edge[now.yy])
        {
            int newD = dist[now.yy] + e.w;
            if (dist[e.to] != -1 && dist[e.to] < newD)
                continue;
            dist[e.to] = newD;
            pq.emplace(dist[e.to], e.to);
        }
    }
    
    for (int i = 1; i <= v; i++)
    {
        if (dist[i] != -1)
            printf("%d\n", dist[i]);
        else
            printf("INF\n");
    }
}

int main() {
    int v, e, k;
    scanf("%d %d %d", &v, &e, &k);
    
    for (int i = 1; i <= e; i++)
    {
        int a, b, t;
        scanf("%d %d %d", &a, &b, &t);
        
        edge[a].emplace_back(b, t);
    }
    
    calc(k, v);
    
    return 0;
}