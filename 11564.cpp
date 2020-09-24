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
    i64 k, a, b;
    cin >> k >> a >> b;

    if ((a < 0 && b > 0) || (a > 0 && b < 0))
    {
        a = abs(a);
        b = abs(b);

        cout << a / k + b / k + 1;
        return 0;
    }

    a = abs(a);
    b = abs(b);
    if (a > b)
        swap(a, b);

    i64 ans = b / k - a / k;

    if (a % k == 0)
        ans++;
    cout << ans << endl;

    return 0;
}