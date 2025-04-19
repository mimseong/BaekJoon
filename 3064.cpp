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

int xi[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int yi[] = {1, 1, 1, 0, 0, -1, -1, -1};

int num_of_mine(int x, int y, vector<string> &v) {
    int mine_count = 0;

    FOR (i, 9) {
        int nx = x + xi[i];
        int ny = y + yi[i];

        if (0 <= nx && nx < v.size() && 0 <= ny && ny < v.size() && v[nx][ny] == 'O') {
            mine_count++;
        }
    }

    return mine_count;
}

void solve() {
    int n;
    cin >> n;

    vector<string> v(n);
    FOR (i, n) {
        cin >> v[i];
    }

    int ans = 0;
    // X -> 지뢰 없음, O -> 지뢰 있음
    FOR (i, n - 2) {
        ii now = make_pair(i, 0);
        ii to_check = make_pair(i+1, 1);

        int count = num_of_mine(now.xx, now.yy, v);

        if (v[now.xx][now.yy] - '0' == count)
            v[to_check.xx][to_check.yy] = 'X';
        else if (v[now.xx][now.yy] - '0' - 1 == count) {
            v[to_check.xx][to_check.yy] = 'O';
            ans++;
        }
        else
            cout << "ERROR\n";
    }

    for (int i = 1; i < n-2; i++) {
        ii now = make_pair(n-1, i);
        ii to_check = make_pair(n-2, i+1);

        int count = num_of_mine(now.xx, now.yy, v);

        if (v[now.xx][now.yy] - '0' == count)
            v[to_check.xx][to_check.yy] = 'X';
        else if (v[now.xx][now.yy] - '0' - 1 == count) {
            v[to_check.xx][to_check.yy] = 'O';
            ans++;
        }
        else
            cout << "ERROR\n";
    }

    for (int i = n-2; i >= 2; i--) {
        ii now = make_pair(i, n-1);
        ii to_check = make_pair(i-1, n-2);

        int count = num_of_mine(now.xx, now.yy, v);

        if (v[now.xx][now.yy] - '0' == count)
            v[to_check.xx][to_check.yy] = 'X';
        else if (v[now.xx][now.yy] - '0' - 1 == count) {
            v[to_check.xx][to_check.yy] = 'O';
            ans++;
        }
        else
            cout << "ERROR\n";
    }

    for (int i = n-2; i >= 3; i--) {
        ii now = make_pair(0, i);
        ii to_check = make_pair(1, i-1);

        int count = num_of_mine(now.xx, now.yy, v);

        if (v[now.xx][now.yy] - '0' == count)
            v[to_check.xx][to_check.yy] = 'X';
        else if (v[now.xx][now.yy] - '0' - 1 == count) {
            v[to_check.xx][to_check.yy] = 'O';
            ans++;
        }
        else
            cout << "ERROR\n";
    }

    int center = 0;
    if (n > 4)
        center = (n-4)*(n-4);

    cout << ans + center << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	FOR(i, n)
	    solve();

	return 0;
}
