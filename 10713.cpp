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

using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int stack_[200005];

int     main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> p(m);
    for (int i = 0; i < m; i++)
        scanf("%d", &p[i]);

    vector<i64> sum(n + 5);

    for (int i = 0; i < m - 1; i++)
    {
        if (p[i] < p[i + 1])
        {
            sum[p[i]] += 1;
            sum[p[i + 1]] += -1;
        }
        else
        {
            sum[p[i + 1]] += 1;
            sum[p[i]] += -1;
        }
    }

    for (int i = 1; i <= n; i++)
        sum[i] = sum[i] + sum[i - 1];

    i64 ans = 0;
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        if (sum[i] != 0)
            ans += min(a*sum[i], b*sum[i] + c);
    }

    printf("%lld\n", ans);

    return 0;
}