#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

i64 dp[3003][3003];

int     main()
{
    int s;
    string str;

    cin >> s >> str;

    dp[0][0] = 1;
    for (int i = 1; i <= str.size(); i++)
    {
        i64 sum = 0;
        for (int j = 0; j <= s; j++)
        {
            sum = (sum + dp[i - 1][j]) % MOD;

            if (j > 25)
                sum = (sum - dp[i - 1][j - 26] + MOD) % MOD;
            dp[i][j] = sum;
        }
    }

    cout << dp[str.size()][s];

    return 0;
}