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
#include <cstring>
#include <bitset>

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()
#define MAXV 1000000

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

int     main()
{
    vector<i64> sum(10005);

    sum[1] = 1;
    for (int i = 2; i <= 10000; i++)
        sum[i] += sum[i - 1] + i;

    int n;
    scanf("%d", &n);

    i64 ans = 0;
    for (int i = 1; i <= n; i++)
        ans += sum[i];

    for (int i = n - 1; i > 0; i -= 2)
        ans += sum[i];

    printf("%lld\n", ans);

    return 0;
}