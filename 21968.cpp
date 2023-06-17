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

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()
#define MAXV 987654321

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

void solve() {
    i64 n;
    scanf("%lld", &n);

    bitset<10000> b(n);
    // cout << b << "\n";

    i64 ans = 0;
    for (i64 i = 0, three = 1; i < 50; i++, three *= 3) {
        if (b[i] == 1)
            ans += three;
    }
    printf("%lld\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}
