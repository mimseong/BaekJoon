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

int ans = 0;
int cube[25];
int two[25];

bool res = true;

void solve(int l, int w, int h, int i)
{
    if (i == -1)
    {
        if (l > 0 && w > 0 && h > 0)
            res = false;
        
        return;
    }

    if (two[i] > l || two[i] > w || two[i] > h || cube[i] == 0)
    {
        solve(l, w, h, i - 1);
        return;
    }

    cube[i]--;
    ans++;

    solve(l, w - two[i], two[i], i);
    solve(l - two[i], two[i], two[i], i);
    solve(l, w, h - two[i], i);
}

int     main()
{
    int l, w, h;
    scanf("%d %d %d", &l, &w, &h);

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        cube[a] = b;
    }

    for (int i = 1, j = 0; j < 20; i *= 2, j++)
        two[j] = i;

    solve(l, w, h, 19);

    if (!res)
        printf("-1\n");
    else
        printf("%d\n", ans);

    return 0;
}