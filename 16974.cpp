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

i64 N, X;
i64 v[55];
i64 p[55];

int main() {
	scanf("%lld %lld", &N, &X);

	v[0] = 1;
	p[0] = 1;
	for (i64 i = 1; i <= 50; i++) {
	    v[i] = 2 * v[i-1] + 3;
	    p[i] = 2 * p[i-1] + 1;
	}

	i64 ans = 0;
	i64 x = X;
	for (i64 i = N; i >= 0; i--) {
	   // printf("v[i]:%lld, ans:%lld, x:%lld\n", v[i], ans, x);

	    // 가장 마지막 패티인 경우
	    if (x == v[i]) {
	       // printf("마지막\n");
	        ans += p[i];
	        break;
	    }

	    // 중간 패티인 경우
	    i64 mid = v[i] / 2 + 1;
	    if (x == mid) {
	       // printf("중간\n");
	        ans += p[i-1] + 1;
	        break;
	    }

	    // 첫 패티인 경우
	    if (x == 1) {
	       // printf("처음\n");
	        break;
	    }

	    // 중간 앞부분 패티인 경우
	    if (x < mid) {
	       // printf("중간앞\n");
	        x -= 1;
	        continue;
	    }

	    // 중간 뒷부분 패티인 경우
	    if (mid < x) {
	       // printf("중간뒤\n");
	        ans += p[i-1] + 1;
	        x -= v[i-1] + 2;
	        continue;
	    }
	}

	printf("%lld\n", ans);

	return 0;
}
