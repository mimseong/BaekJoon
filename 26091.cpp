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

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;


int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    sort(all(v));

    // for (int i = 0; i < n; i++)
    //     printf("%d ", v[i]);

    int l = 0, r = n-1;

    int ans = 0;
    while(l < r) {
        if (v[l] + v[r] >= m) {
            ans++;
            r--;
        }
        l++;
    }

    printf("%d\n", ans);

    return 0;
}
