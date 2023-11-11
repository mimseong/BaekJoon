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

int N;
i64 v[2005];
i64 dp[2005][2005];

i64 ioi(int li, int ri);
i64 joi(int li, int ri);

int left(int idx) {
    return (idx-1+N)%N;
}

int right(int idx) {
    return (idx+1)%N;
}

i64 ioi(int li, int ri) {
    if (left(li) == ri)
        return 0;
    if (v[left(li)] > v[right(ri)])
        return joi(left(li), ri);
    return joi(li, right(ri));
}

i64 joi(int li, int ri) {
    auto& ret = dp[li][ri];
    if (ret != -1)
        return ret;
    if (left(li) == ri)
        return 0;
    i64 ans1 = v[left(li)] + ioi(left(li), ri);
    i64 ans2 = v[right(ri)] + ioi(li, right(ri));
    return ret = max(ans1, ans2);
}

int main() {
	scanf("%d", &N);

	FOR(i, N) scanf("%lld", &v[i]);
	memset(dp, -1, sizeof(dp));

	i64 ans = 0;
	FOR(i, N) {
	    ans = max(ans, v[i] + ioi(i, i));
	}
	printf("%lld\n", ans);

	return 0;
}
