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

string s, t;
bool ans = false;

void solve(string str){
    if (str == s) {
        ans = true;
        return;
    }

    if (str[str.size() - 1] == 'A') {
        solve(str.substr(0, str.size() - 1));

    }

    if (str[0] == 'B') {
        string res = str.substr(1, str.size());
        reverse(all(res));
        solve(res);
    }
}

int main() {
    cin >> s >> t;

    solve(t);

    cout << ans;

    return 0;
}
