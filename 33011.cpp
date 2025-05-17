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
#include <cassert>
#include <climits>
#include <tuple>

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()
#define MAXV 987654321
#define FOR(i, n) for (int i = 0; i < (n); ++i)

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

void solve() {
    int n;
    scanf("%d", &n);

    int odd = 0;
    int even = 0;
    FOR (i, n) {
        int x;
        scanf("%d", &x);

        if (x % 2 == 0) even++;
        else odd++;
    }

    if (odd == even) {
        printf("heeda0528\n");
        return;
    }

    int maxv = max(odd, even);

    if (maxv % 2 == 0) {
        printf("heeda0528\n");
    } else {
        printf("amsminn\n");
    }
}

int main()
{
  int t;
  scanf("%d", &t);

  FOR (i, t) solve();

  return 0;
}
