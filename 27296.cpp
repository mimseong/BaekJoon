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

void solve() {
    i64 n;
    scanf("%lld", &n);

    if (n <= 1) {
        printf("1 0\n");
        return;
    }
    else {
        printf("0 1\n");
        return;
    }
}

int main() {
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
	    solve();
	}

	return 0;
}
