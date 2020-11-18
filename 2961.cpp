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

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int     main()
{
    int n;
    cin >> n;

    vector<ii> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].xx >> v[i].yy;
    i64 minv = 1000000005;
    for (int i = 1; i < (1 << v.size()); i++)
    {
        ii64 res;

        res.xx = 1, res.yy = 0;
        for (int j = 0; j < v.size(); j++)
        {
            if (i & (1 << j))
            {
                res.xx *= v[j].xx;
                res.yy += v[j].yy;
            }
        }
        if (minv > abs(res.xx - res.yy))
            minv = abs(res.xx - res.yy);
    }

    cout << minv;

    return 0;
}