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

int     main()
{
    int n;
    cin >> n;

    int m = 64;
    int count = 0;
    while (n > 0)
    {
        if (n < m)
        {
            m /= 2;
            continue;
        }

        n -= m;
        count++;
    }
    cout << count << endl;

    return 0;
}