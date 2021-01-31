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

int mapv[105][105];
i64 dp[105][105];

int     main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mapv[i][j]);

    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] == 0 || (i == n - 1 && j == n - 1))
                continue;
            
            int ny = j + mapv[i][j];
            if (ny < n)
                dp[i][ny] += dp[i][j];
            int nx = i + mapv[i][j];
            if (nx < n)
                dp[nx][j] += dp[i][j];
        }
    }
    
    printf("%lld\n", dp[n - 1][n - 1]);

    return 0;
}