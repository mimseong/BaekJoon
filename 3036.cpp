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

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

int     main()
{
    int n;
    scanf("%d", &n);

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    for (int i = 1; i < n; i++)
    {
        int tmp = GCD(max(v[0], v[i]), min(v[0], v[i]));
        printf("%d/%d\n", v[0] / tmp, v[i] / tmp);
    }

    return 0;
}