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

int v[200005];
int n;

int solve(int a, int b) {
    int r = 1;
    int ans = 0;

    for (int l = 1; l <= n; l++) {
        r = max(l, r);
        while (r < n && (v[r] == a || v[r] == b) && (v[r + 1] == a || v[r + 1] == b))
            r++;

        ans = max(ans, r - l + 1);
    }

    return ans;
}

int main() {
	scanf("%d", &n);

	FOR (i, n) {
	    scanf("%d", &v[i+1]);
	}

    int ans = 0;



    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            ans = max(solve(i, j), ans);
        }
    }


    printf("%d\n", ans);

	return 0;
}
