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
#include <cassert>
#include <climits>
#include <tuple>

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()
#define MAXV 987654321
#define FOR(i, n) for (int i = 0; i < (n); ++i)

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    map<char, int> current_group_num;
    map<char, int> group_size;

    FOR (i, s.size()) {
        current_group_num[s[i]] = i;
        group_size[s[i]]++;
    }

    vector<pair<int, char>> v(n);
    FOR (i, s.size()) {
        v[i].yy = s[i];
        v[i].xx = current_group_num[s[i]];
    }

    sort(all(v));

    map<char, int> ordered_group_num;
    FOR (i, n) {
        ordered_group_num[v[i].yy] = i;
    }

    int ans = 0;
    for (auto ordered : ordered_group_num) {
        char group = ordered.xx;
        int changed_idx = ordered.yy;
        int origin_idx = current_group_num[group];

        // cout << group << "\n";
        ans += (origin_idx - changed_idx) * group_size[group] * 5;
    }

    cout << ans << "\n";
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int t;
  cin >> t;

  FOR (i, t) solve();

  return 0;
}
