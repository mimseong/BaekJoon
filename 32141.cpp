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
	int n, h;
	scanf("%d %d", &n, &h);

	vector<int> v(n);
	FOR (i, n) scanf("%d", &v[i]);

	sort(all(v));

	FOR (i, n) {
	    h -= v[i];
	    if (h <= 0) {
	        printf("%d\n", i + 1);
	        return 0;
	    }
	}

    printf("-1");
	return 0;
}


