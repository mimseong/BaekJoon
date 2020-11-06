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
    int h, w;
    scanf("%d %d", &h, &w);

    vector<int> v(w);
    for (int i = 0; i < w; i++)
        scanf("%d", &v[i]);

    int pre = v[0];
    int tmp = 0;
    int sumv = 0;

    for (int i = 1; i < w; i++)
    {
        if (pre <= v[i])
        {
            pre = v[i];
            sumv += tmp;
            tmp = 0;
        }
        tmp += pre - v[i];
    }

    pre = v[w - 1];
    tmp = 0;
    for (int i = w - 2; i >= 0; i--)
    {
        if (pre < v[i])
        {
            pre = v[i];
            sumv += tmp;
            tmp = 0;
        }
        tmp += pre - v[i];
    }

    printf("%d\n", sumv);

    return 0;
}