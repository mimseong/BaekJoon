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
#define MOD 10007

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

int cache[1005];
int ans;

int func(int n)
{
    if (n == 0)
    {
        return 1;
    }

    if (cache[n] != -1)
        return cache[n];

    int a = 0, b = 0;
    if (n >= 2)
        a = func(n - 2);
    b = func(n - 1);

    return cache[n] = a % MOD + b % MOD;
}

int     main()
{
    int n;
    scanf("%d", &n);

    memset(cache, -1, sizeof(cache));
    func(n);
    printf("%d\n", cache[n] % MOD);

    return 0;
}