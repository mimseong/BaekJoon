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

string mapv[120];
bool visited[120][120];
ii backtrack[120][120];
int n, m;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
	    cin >> mapv[i];
	}

	queue<ii> Q;
    Q.push({0, 0});
    visited[0][0] = true;

    while (!Q.empty())
    {
        auto curr = Q.front();
        int x = curr.xx; int y = curr.yy;
        // printf("curr: %d %d\n", x, y);
        Q.pop();

        // 도착
        if (curr.xx == n-1 && curr.yy == m-1) break;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || n <= nx)
                continue;
            if (ny < 0 || m <= ny)
                continue;
            if (visited[nx][ny])
                continue;
            if (mapv[nx][ny] == '*')
                continue;

            // printf("%d %d\n", nx, ny);
            visited[nx][ny] = true;
            backtrack[nx][ny] = make_pair(x, y);
            Q.push({nx, ny});
        }
    }

    vector<ii> st;
    ii start = make_pair(0, 0);
    ii curr = make_pair(n-1, m-1);
	while (curr != start) {
		st.emplace_back(curr);
		curr = backtrack[curr.first][curr.second];
	}

	cout << start.xx + 1 << ' ' << start.yy + 1 << '\n';
	while (!st.empty()) {
		cout << st.back().xx + 1 << ' ' << st.back().yy + 1 << '\n';
		st.pop_back();
	}

	return 0;
}
