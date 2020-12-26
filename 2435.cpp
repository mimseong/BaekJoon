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
    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += v[i];
    
    int max = sum;
    for (int i = k; i < n; i++)
    {
        sum += v[i];
        sum -= v[i - k];
        if (max < sum)
            max = sum;
    }
    printf("%d\n", max);

    return 0;
}