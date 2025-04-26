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
    int n;
    scanf("%d", &n);
    
    vector<int> arr(n + 1);
    vector<int> dp(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = i; j > 0; j--) {
            if (dp[j - 1] == 0) continue;
            if (dp[j - 1] >= arr[i]) dp[j] = max(dp[j], dp[j - 1] + arr[i]);
        }
        dp[1] = max(dp[1], arr[i]);
    }
    
    for (int i = n; i > 0; i--) {
        if (dp[i]) {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}