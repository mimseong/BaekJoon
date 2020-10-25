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
using iii = tuple<int, int, int>;

using namespace std;

struct st {
    int n;
    int g;
    int s;
    int b;
};

bool sort_by_struct(struct st a, struct st b)
{
    if (a.g == b.g && a.s == b.s)
        return a.b > b.b;
    if (a.g == b.g)
        return a.s > b.s;
    return a.g > b.g;
}

int     main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    vector<struct st> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].n >> v[i].g >> v[i].s >> v[i].b;

    sort(v.begin(), v.end(), sort_by_struct);

    int count = 1;

    if (v[0].n == k)
    {
        printf("%d\n", count);
        return 0;
    }

    for (int i = 1; i < n; i++)
    {
        if (v[i].g != v[i - 1].g ||
            v[i].s != v[i - 1].s ||
            v[i].b != v[i - 1].b)
            count = i + 1;

        if (v[i].n == k)
        {
            printf("%d\n", count);
            return 0;
        }
    }
    
    return 0;
}