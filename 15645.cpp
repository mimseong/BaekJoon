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
#define MAXV 1000000

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

int min_cache[100005][3];
int max_cache[100005][3];
int v[100005][3];
int n;

int     func_min(int i, int j)
{
    if (i == n + 1)
        return 0;

    int& ref = min_cache[i][j];
    if (ref != -1)
        return ref;

    int a = MAXV, b = MAXV, c = MAXV;
    if (j == 1 || j == 0)
        a = func_min(i+1, 0);
    b = func_min(i + 1, 1);
    if (j == 1 || j == 2)
        c = func_min(i + 1, 2);

    return ref = v[i][j] + min({ a, b, c });
}

int     func_max(int i, int j)
{
    if (i == n + 1)
        return 0;

    int& ref = max_cache[i][j];
    if (ref != -1)
        return ref;

    int a = 0, b = 0, c = 0;
    if (j == 1 || j == 0)
        a = func_max(i + 1, 0);
    b = func_max(i + 1, 1);
    if (j == 1 || j == 2)
        c = func_max(i + 1, 2);

    return ref = v[i][j] + max({ a, b, c });
}



int     main()
{
    memset(min_cache, -1, sizeof(min_cache));
    memset(max_cache, -1, sizeof(max_cache));

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d %d %d\n", &v[i][0], &v[i][1], &v[i][2]);

    func_min(0, 1);
    func_max(0, 1);

    printf("%d %d\n", max_cache[0][1], min_cache[0][1]);
    
    return 0;
}