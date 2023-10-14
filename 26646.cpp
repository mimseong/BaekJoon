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
    int n;
    scanf("%d", &n);

    vector<i64> v(n);

    for (int i = 0; i < n; i++) {
        scanf("%lld", &v[i]);
    }

    i64 ans = 0;

    ans += 2 * v[0] * v[0];
    for (int i = 1; i < n - 1; i++) {
        ans += 4 * v[i] * v[i];
    }
    ans += 2 * v[n-1] * v[n-1];

    printf("%d\n", ans);

	return 0;
}
