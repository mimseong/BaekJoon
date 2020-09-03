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

int     main()
{
    int n;
    scanf("%d", &n);

    int e;
    scanf("%d", &e);

    vector<i64> ans(105);
    i64 num_one = 1;
    i64 comp = 1;
    for (int i = 0; i < e; i++)
    {
        int k;
        scanf("%d", &k);

        bool is_one = false;
        vector<int> v(k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &v[j]);
            if (v[j] == 1)
                is_one = true;
        }

        if (is_one)
        {
            for (int j = 0; j < k; j++)
                ans[v[j]] |= num_one;
            num_one = num_one << 1;
            comp |= comp << 1;
        }
        else
        {
            i64 tmp = 0;
            for (int j = 0; j < k; j++)
                tmp |= ans[v[j]];

            for (int j = 0; j < k; j++)
                ans[v[j]] = tmp;
        }
    }

    comp = ~(num_one)&comp;

    for (int i = 1; i < 101; i++)
    {
        if ((ans[i] & comp) == comp)
            printf("%d\n", i);
    }

    return 0;
}