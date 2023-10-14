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

i64 v[2000005];

int main() {
	i64 x, y;
	scanf("%lld %lld", &x, &y);

	if (x == 0 && y == 0) {
	    printf("0");
	    return 0;
	}

	int idx;
	bool isPossible = false;
	for (int i = 1; v[i-1] <= 2000000000005; i++) {
	    v[i] = v[i-1] + i;
	    if (x + y == v[i]) {
	        isPossible = true;
	        idx = i;
	        break;
	    }
	}

	if (!isPossible) {
	    printf("-1\n");
	    return 0;
	}

	int ans = 0;
// 	printf("%lld\n\n", v[idx]);

	i64 xx = x;
	for (i64 i = idx; i > 0 && xx >= 0; i--) {
	    if (i <= xx) {
	        ans++;
	        xx -= i;
	       // printf("%lld\n", i);
	    }
	}

	assert(xx == 0);
// 	printf("----------\n");
	printf("%lld\n", ans);

	return 0;
}
