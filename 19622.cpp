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

int dp[100005];

int main() {
    int n;
    scanf("%d", &n);

    vector<ii> time(n);
    vector<int> num(n);

    FOR(i, n) {
        scanf("%d %d %d", &time[i].xx, &time[i].yy, &num[i]);
    }

    dp[0] = num[0];

    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i-1], num[i] + dp[i-2]);
    }

    printf("%d", dp[n-1]);


	return 0;
}
