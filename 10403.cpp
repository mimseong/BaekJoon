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

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

vector<ii> edge[100005];
bool friends[100005];
bool visited[100005];
int path[100005];

int total;

bool dfs(int node) {
    bool res = friends[node];
    visited[node] = true;

    for(auto[e, c]: edge[node]) {
        if (visited[e]) continue;

        path[e] = path[node] + c;
        if (dfs(e)) {
            res = true;
            total += c;
        }
    }

    return res;
}

int main() {
    int n, f;
    scanf("%d %d", &n, &f);

    for (int i = 0; i < n-1; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edge[a].emplace_back(b, c);
		edge[b].emplace_back(a, c);
    }

    for (int i = 0; i < f; i++) {
        int a;
        scanf("%d", &a);
        friends[a] = true;
    }

    dfs(1);

    int maxv = 0;
    for (int i = 1; i <= n; i++) {
        if (friends[i])
            maxv = max(maxv, path[i]);
    }

    printf("%d\n", total - maxv);

    return 0;
}
