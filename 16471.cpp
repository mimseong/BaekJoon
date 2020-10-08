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

int     main()
{
    int n;
    scanf("%d", &n);

    vector<int> v1(n);
    vector<int> v2(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &v2[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &v1[i]);

    sort(all(v1));
    sort(all(v2));

    int count = 0;
    for (int i = 0, j = 0; i < n && j < n; i++)
    {
        if (v1[i] > v2[j])
        {
            j++, count++;
        }
    }
    
    if (count >= (n + 1) / 2)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}