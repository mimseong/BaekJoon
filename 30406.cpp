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

vector<int> v(4);

int solve(int i, int j, int point) {
    int x = min(v[i], v[j]);

    int ans = point * x;
	v[i] -= x;
	v[j] -= x;

	return ans;
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
	    int x;

	    scanf("%d", &x);
	    v[x]++;
	}

	int ans = 0;
	ans += solve(0, 3, 3);
	ans += solve(1, 2, 3);
	ans += solve(0, 2, 2);
	ans += solve(1, 3, 2);
	ans += solve(0, 1, 1);
	ans += solve(2, 3, 1);

	printf("%d\n", ans);

	return 0;
}
