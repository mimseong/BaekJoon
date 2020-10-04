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

i64 v[100005][2];

int main() 
{
    v[1][1] = 1;

    v[2][0] = 1;
    v[2][1] = 1;

    v[3][0] = 2;
    v[3][1] = 2;

    for (int i = 4; i <= 100000; i++)
    {
        v[i][0] = v[i - 1][1] % MOD + v[i - 2][1] % MOD + v[i - 3][1] % MOD;
        v[i][1] = v[i - 1][0] % MOD + v[i - 2][0] % MOD + v[i - 3][0] % MOD;
    }

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        printf("%lld %lld\n", v[n][1] % MOD, v[n][0] % MOD);
    }

    return 0;
}