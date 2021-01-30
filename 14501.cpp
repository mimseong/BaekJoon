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

    vector<ii> v(n + 1);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &v[i].xx, &v[i].yy);

    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++)
        dp[i] = v[i].yy;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (i - j < v[j].xx)
                continue;

            dp[i] = max(v[i].yy + dp[j], dp[i]);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i + v[i].xx > n + 1)
            continue;

        res = max(res, dp[i]);
    }

    printf("%d\n", res);

    return 0;
}