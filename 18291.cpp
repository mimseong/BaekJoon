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

#define MOD 1000000007

i64 ipow(i64 n, i64 x)
{
    if (x == 0)
        return 1;

    i64 half = ipow(n, x / 2);
    half = (half * half) % MOD;

    if (x % 2 == 0)
        return half;

    return (half * n) % MOD;
}

int     main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        cout << ipow(2, max(0, n - 2)) << endl;
    }

    return 0;
}
