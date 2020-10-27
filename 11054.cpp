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
    int n;
    scanf("%d", &n);

    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);

    vector<int> d1(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int maxv = d1[0];
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j] && maxv < d1[j])
                maxv = d1[j];
        }
        d1[i] = maxv + 1;
    }

    vector<int> d2(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int maxv1 = d1[0];
        int maxv2 = d2[0];
        for (int j = 0; j < i; j++)
        {
            if (v[i] < v[j] && maxv1 < d1[j])
                maxv1 = d1[j];
            if (v[i] < v[j] && maxv2 < d2[j])
                maxv2 = d2[j];
        }
        d2[i] = max(maxv1, maxv2) + 1;
    }

    printf("%d\n", *max_element(all(d2)));

    return 0;
}