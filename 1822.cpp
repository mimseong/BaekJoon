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


int     main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> va(n);
    vector<int> vb(m);
    for (int i = 0; i < n; i++)
        scanf("%d", &va[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &vb[i]);

    sort(all(va));
    sort(all(vb));

    vector<int> ans;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (va[i] < vb[j])
        {
            ans.push_back(va[i]);
            i++;
        }
        else if (va[i] > vb[j])
            j++;
        else
            i++, j++;
    }

    for ( ;i < n; i++)
    {
        ans.push_back(va[i]);
    }

    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++)
        printf("%d ", ans[i]);

    return 0;
}