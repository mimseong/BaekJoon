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
#define U 1
#define D 2
#define L 3
#define R 4


using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

void    solve()
{
    int m, n, x, y;
    scanf("%d %d %d %d", &m, &n, &x, &y);
    x--;
    y--;

    for (int i = x; i < (n * m); i += m)
    {
        if (i % n == y)
        {
            printf("%d\n", i + 1);
            return;
        }
    }
    printf("-1\n");
}

int     main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
        solve();

    return 0;
}