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

int mapv[105][105];
int n, m;
int x[] = {0, 1, 0, -1};
int y[] = {1, 0, -1, 0};

int solve(int start) {
    int pos_x = start;
    int pos_y = 0;
    map<iii, bool> check;

    int i = 0;
    while(true) {
        check[make_tuple(pos_x,pos_y, i%4)] = true;

        pos_x += mapv[pos_x][pos_y] * x[i%4];
        pos_y += mapv[pos_x][pos_y] * y[i%4];
        i++;

        // printf("%d %d\n", pos_x, pos_y);

        if (pos_x < 0 || n <= pos_x) return -1;
        if (pos_y < 0 || m <= pos_y) return -1;

        // 방향까지 같아야 한다
        if (check[make_tuple(pos_x,pos_y, i%4)]) return start;
    }

    return start;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < m; j++) {
	        scanf("%d", &mapv[i][j]);
	    }
	}

	vector<int> ans;
	for (int i = 0; i < n; i++) {
	   // printf("----%d---\n", i);
	    int start = solve(i);

	    if (start != -1) ans.push_back(start+1);
	}

	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
	    printf("%d ", ans[i]);
	}

	return 0;
}
