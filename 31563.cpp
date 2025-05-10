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

int main()
{
    int n, q, cmd, a, b, idx = 0;
    scanf("%d %d", &n, &q);
    
    vector<long long> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &arr[i]);
        arr[i] += arr[i - 1];
    }
    
    while (q--) {
        scanf("%d %d", &cmd, &a);
        if (cmd == 3) {
            scanf("%d", &b);
            
            a = (a - 1 + idx) % n;
            b = (b - 1 + idx) % n;
            
            if (a <= b) {
                printf("%lld\n", arr[b + 1] - arr[a]);
            } else {
                printf("%lld\n", arr[n] - (arr[a] - arr[b + 1]));
            }
        } else {
            idx += (cmd == 1) ? -a : a;
            idx = (idx + n) % n;
        }
    }
    
    return 0;
}