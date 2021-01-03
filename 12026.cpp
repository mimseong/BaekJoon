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

int dp[1005];

char find_nxt(char c)
{
    if (c == 'B')
        return 'O';
    if (c == 'O')
        return 'J';
    if (c == 'J')
        return 'B';
    return 'Z';
}

int     main()
{
    int n;
    string str;

    cin >> n >> str;
    
    memset(dp, -1, sizeof(dp));

    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == -1)
            continue;

        char nxt = find_nxt(str[i]);
        for (int j = i + 1; j < n; j++)
        {
            if (nxt != str[j])
                continue;

            if (dp[j] == -1)
                dp[j] = dp[i] + (j - i) * (j - i);
            dp[j] = min(dp[i] + (j - i) * (j - i), dp[j]);
        }
    }

    cout << dp[n-1];

    return 0;
}