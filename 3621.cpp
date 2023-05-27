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

int v[100005];

int main() {
    int n, d;
    scanf("%d %d", &n, &d);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        v[x]++;
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (v[i] > d)
            ans += (v[i] - 2) / (d - 1);
    }

    printf("%d", ans);

    return 0;
}
