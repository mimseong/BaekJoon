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
#define MOD 1000000000

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

int cache[105][10];
int ans;

int    calc(int before, int len)
{
    if (len == 0)
        return 1;

    int& ref = cache[len][before];

    if (ref != -1)
        return ref;

    int a = 0, b = 0;
    if (before != 0)
        a = calc(before - 1, len - 1);
    if (before != 9)
        b = calc(before + 1, len - 1);

    return ref = (a + b) % MOD;
}

void    func(int len)
{
    for (int i = 1; i < 10; i++)
    {
        ans = (calc(i, len - 1) + ans) % MOD;
    }
}

int     main()
{
    int n;
    scanf("%d", &n);

    memset(cache, -1, sizeof(cache));

    func(n);
    cout << ans << endl;

    return 0;
}