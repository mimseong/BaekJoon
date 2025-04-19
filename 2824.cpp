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
#define MAXV 1000000000
#define FOR(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

i64 gcd(i64 a, i64 b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	int n;
	scanf("%d", &n);

	vector<i64> vn(n);
	for (int i = 0; i < n; i++)
	    scanf("%lld", &vn[i]);

	int m;
	scanf("%d", &m);
	vector<i64> vm(m);
	for (int i = 0; i < m; i++)
	    scanf("%lld", &vm[i]);

	i64 ans = 1;
	bool isFormat = false;
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < m; j++) {
	        i64 res = vn[i] > vm[j] ? gcd(vn[i], vm[j]) : gcd(vm[j], vn[i]);
	        ans *= res;
	        if (ans >= MAXV) {
	            ans %= MAXV;
	            isFormat = true;
	        }

	        vn[i] /= res;
	        vm[j] /= res;
	    }
	}

	if (isFormat)
	    printf("%09lld", ans);
	else
	    printf("%lld", ans);

	return 0;
}


