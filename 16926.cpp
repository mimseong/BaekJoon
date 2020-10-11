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
#include <bitset>

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()

using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int n, m;
int v[300][300];
int tmp[300][300];

void rotate(int now, int depth)
{
    if (now == depth)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                v[i][j] = tmp[i][j];
        }
        return;
    }

    int s = now, eN = n - now, eM = m - now;

    for (int i = s; i < eN - 1; i++)
        tmp[i + 1][s] = v[i][s];
    for (int i = s; i < eM - 1; i++)
        tmp[eN - 1][i + 1] = v[eN - 1][i];
    for (int i = eN - 1; i > s; i--)
        tmp[i - 1][eM - 1] = v[i][eM - 1];
    for (int i = eM - 1; i > s; i--)
        tmp[s][i - 1] = v[s][i];

    rotate(now + 1, depth);
}

int     main()
{
    int r;
    cin >> n >> m >> r;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> v[i][j];
    }

    for (int i = 0; i < r; i++)
    {
        rotate(0, min(n, m) / 2);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", tmp[i][j]);
        printf("\n");
    }

    return 0;
}