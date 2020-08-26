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


int     main()
{
    int n;
    scanf("%d", &n);

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    vector<int> count(8005, 0);

    i64 sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        count[v[i] + 4000]++;
    }
    printf("%.0lf\n", round((double)sum / n));
    
    sort(all(v));
    printf("%d\n", v[n/2]);

    int maxn = 0;
    for (int i = 0; i < 8005; i++)
    {
        if (count[i] > maxn)
            maxn = count[i];
    }

    bool isOne = false;
    int ans;
    for (int i = 0; i < 8005; i++)
    {
        if (count[i] != maxn)
            continue;

        ans = i;
        if (!isOne)
            isOne = true;
        else
            break;
    }


    printf("%d\n", ans - 4000);

    printf("%d\n", v[n-1] - v[0]);

    return 0;
}