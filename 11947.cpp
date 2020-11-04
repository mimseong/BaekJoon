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

i64     check_mid(i64 n)
{
    i64 max_num = 1;

    string s = to_string(n);
    for (int i = 0; i < s.size(); i++)
        max_num *= 10;

    return max(max_num / 2 - 1, 0ll);
}

i64     func(string s)
{
    string tmp = "";

    for (int i = 0; i < s.size(); i++)
        tmp += '9' - s[i] + '0';

    return stol(tmp);
}

int     main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        i64 n;
        scanf("%lld", &n);

        i64 res = check_mid(n);

        if (res < n)
            printf("%lld\n", res * (res + 1));
        else
            printf("%lld\n", n * func(to_string(n)));
    }

    return 0;
}