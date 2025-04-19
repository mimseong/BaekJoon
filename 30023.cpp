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

int jump_count(char asis, char tobe) {
    if (asis == 'R' && tobe == 'G')
        return 1;
    else if (asis == 'R' && tobe == 'B')
        return 2;
    else if (asis == 'G' && tobe == 'B')
        return 1;
    else if (asis == 'G' && tobe == 'R')
        return 2;
    else if (asis == 'B' && tobe == 'R')
        return 1;
    else if (asis == 'B' && tobe == 'G')
        return 2;
    return 0;
}

char jump_char(char asis, int count) {
    if (asis == 'R' && count == 1)
        return 'G';
    else if (asis == 'R' && count == 2)
        return 'B';
    else if (asis == 'G' && count == 1)
        return 'B';
    else if (asis == 'G' && count == 2)
        return 'R';
    else if (asis == 'B' && count == 1)
        return 'R';
    else if (asis == 'B' && count == 2)
        return 'G';
    return asis;
}

int solve(char match, int n, string s) {
    int ans = 0;

    for (int i = 0; i <= n - 3; i++) {
        if (s[i] == match)
            continue;

        int count = jump_count(s[i], match);

        for (int j = 0; j < 3; j++) {
            s[i+j] = jump_char(s[i+j], count);
        }

        ans += count;
    }

    bool success = true;
    for (int i = n - 3; i < n; i++) {
        if (s[n-3] != s[i])
            success = false;
    }

    if (success)
        return ans;
    else
        return MAXV;
}

int main() {
    int n;
    string s;

	scanf("%d", &n);
	cin >> s;

	int ans = MAXV;
	ans = min(solve('R', n, s), ans);
	ans = min(solve('G', n, s), ans);
	ans = min(solve('B', n, s), ans);

	if (ans == MAXV)
	    cout << "-1\n";
	else
	    cout << ans << "\n";

	return 0;
}
