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

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);


    vector<int> dp;
    dp.push_back(v[0]);
    for (int i = 1; i < n; i++)
    {
        if (dp[dp.size()-1] < v[i])
        {
            dp.push_back(v[i]);
            continue;
        }
        int pos = lower_bound(all(dp), v[i]) - dp.begin();
        dp[pos] = v[i];
    }
    printf("%d\n", dp.size());
    return 0;
}