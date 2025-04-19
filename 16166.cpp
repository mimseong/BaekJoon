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

map <int, vector<int>> mp;
vector<vector<int>> adj(15);

int bfs(int start, int finish){
    vector<bool> visited(15, false);
    queue<ii> Q;
    Q.push(make_pair(start, 0));
    visited[start] = true;

    while (!Q.empty())
    {
        ii curr = Q.front();
        Q.pop();
        // printf("%d %d\n", curr.xx, curr.yy);

        // finish 호선에 도착하는 경우
        FOR (i, mp[finish].size()) {
            if (curr.xx == mp[finish][i]) {
                return curr.yy;
            }
        }

        for (int next : adj[curr.xx])
        {
            if (!visited[next])
            {
                visited[next] = true;
                Q.push(make_pair(next, curr.yy + 1));
            }
        }
    }

    return MAXV;
}

int main() {
	int n;
	scanf("%d", &n);

	vector<int> start;
	for (int i = 1; i <= n; i++) {
	    int m;
	    scanf("%d", &m);

	    // i 호선의 역 번호 x
	    FOR (j, m) {
	        int x;
	        scanf("%d", &x);

	        // 0번의 호선 저장
	        if (x == 0)
	            start.push_back(i);

	        // x와 연결된 호선 k
	        FOR (k, mp[x].size()) {
	            // i호선과 k호선 연결
	            adj[i].push_back(mp[x][k]);
	            adj[mp[x][k]].push_back(i);
	        }

	        // x에 i호선 추가
	        mp[x].push_back(i);
	        sort(all(mp[x]));
	    }
	}

	int finish;
	scanf("%d", &finish);

// 	for (int i = 0; i < 15; i++) {
// 	    printf("%d: ", i);
// 	    for (int j = 0; j < adj[i].size(); j++) {
// 	        printf("%d ", adj[i][j]);
// 	    }
// 	    printf("\n");
// 	}


	int ans = MAXV;
	FOR (i, start.size()) {

	    ans = min(bfs(start[i], finish), ans);
	}

	if (ans == MAXV)
	    printf("-1\n");
	else
	    printf("%d\n", ans);

	return 0;
}
