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

vector<i64> v[1005];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);


	FOR (i, m) {
	    FOR (j, n) {
	        i64 x;
	        scanf("%lld", &x);
	        v[j].emplace_back(x);
	    }
	}

	vector<i64> ans;
	i64 d = 0;
	FOR (i, n) {
	    sort(all(v[i]));
	    i64 middle = v[i][m/2];
	    ans.emplace_back(middle);
	    FOR (j, v[i].size()) {
	        d += abs(v[i][j] - middle);
	    }
	}

    printf("%lld\n", d);
    FOR (j, ans.size()) {
        printf("%lld ", ans[j]);
    }

	return 0;
}
