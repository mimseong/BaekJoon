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
#include<cassert>
#include <climits>
#include <tuple>

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()
#define MAXV 987654321
#define FOR(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

int inDegree[1005];
int ans[1005];
vector<int> adj[1005];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u].push_back(v);
        inDegree[v]++;
    }

	queue<ii> q;

	for(int i = 1; i <= n; i++){
        if(inDegree[i] == 0) {
            q.push({i, 1});
        }
    }

    for(int i = 0; i < n; i++){
        ii curr = q.front();
        q.pop();

        ans[curr.xx] = curr.yy;
        for(int j = 0; j < adj[curr.xx].size(); j++){
            int next = adj[curr.xx][j];
            if(--inDegree[next] == 0) q.push({next, curr.yy + 1});
        }
    }

	for (int i = 1; i <= n; i++) {
	    printf("%d ", ans[i]);
	}


	return 0;
}
