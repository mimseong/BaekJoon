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

int     main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    vector<int> count(200);

    int nxt = v[0];

    for (int i = 1; ; i++)
    {
        if (count[nxt] == 1)
        {
            printf("-1\n");
            break;
        }

        if (nxt == k)
        {
            printf("%d\n", i);
            break;
        }
        count[nxt]++;
        nxt = v[nxt];
    }
    
    return 0;
}