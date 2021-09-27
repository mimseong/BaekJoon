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
#include <stdlib.h>
#include <string.h>

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

typedef struct Node {
	int x, y;
	i64 cost;
	bool operator < (const Node& o) const {
		return cost > o.cost;
	}
};

i64 x[1010], y[1010], p[1010];
priority_queue<Node> pq;

int Find(int a) {
    if(p[a] == a)
        return a;
    return p[a] = Find(p[a]);
}

int Union(int x, int y) {
    int px = Find(x);
    int py = Find(y);
    
    if (px == py)
        return 0;
    p[px] = py;
    return 1;
}
 
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld", x + i, y + i);
        p[i] = i;
    }
    
    for (int i = 0; i < m; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		Union(from, to);
	}
    
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            i64 dist = (x[i] - x[j]) * (x[i] - x[j]) + (y[i]- y[j]) * (y[i]- y[j]);
            pq.push({i, j, dist});
        }
    }
    
    int cnt = m;
    double res = 0.0;
    
    while(!pq.empty()) {
        if (cnt == n - 1)
            break;
        
        Node cur = pq.top();
        pq.pop();
        
        double cost = cur.cost;
        int cx = cur.x;
        int cy = cur.y;
        
        if (Union(cx, cy) == 1) {
            res += sqrt(cost);
            cnt++;
        }
    }
    
    printf("%.2lf\n", res);
    
    
    
    return 0;
}