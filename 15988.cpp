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
#define MOD 1000000009

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

i64 cache[1000005];

int     main()
{
    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 4;

    for (int i = 4; i <= 1000001; i++)
        cache[i] = cache[i - 1] % MOD + cache[i - 2] % MOD + cache[i - 3] % MOD;

    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);

        printf("%lld\n", cache[n] % MOD);
    }

    return 0;
}