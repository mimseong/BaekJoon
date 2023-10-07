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

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<vector<int>> v(n, vector<int>(m));
	FOR(i, n){
	    FOR(j, m) {
	        scanf("%d", &v[i][j]);
	    }
	}

	sort(all(v));

	FOR(i, n-1){
	    FOR(j, m) {
	        if (v[i][j] > v[i+1][j]) {
	            printf("NO\n");
	            return 0;
	        }
	    }
	}
	printf("YES\n");

	return 0;
}
