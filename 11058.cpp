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

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

int     main()
{
    int n;
    scanf("%d", &n);

    vector<i64> dp(105);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    dp[5] = 5;
    dp[6] = 6;

    for (i64 i = 7; i <= n; i++)
    {
        for (i64 j = 3; j <= i - 1; j++) {
            dp[i] = max({dp[i], dp[i - 1] + 1, dp[i - j] * (j - 1)});
        }
    }

    printf("%lld\n", dp[n]);
    
    return 0;
}