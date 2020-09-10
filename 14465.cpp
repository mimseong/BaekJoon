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
    int n, k, b;
    scanf("%d %d %d", &n, &k, &b);

    vector<bool> v(n + 5, true);

    for (int i = 0; i < b; i++)
    {
        int in;
        scanf("%d", &in);

        v[in] = false;
    }


    int l = 1, r = k;
    int sum = 0;
    for (int i = 1; i <= r; i++)
    {
        if (!v[i])
            sum++;
    }

    int min_num = sum;
    for (int i = r; i <= n; i++)
    {
        r++;
        if (!v[r])
            sum++;
        if (!v[l])
            sum--;
        l++;

        min_num = min(sum, min_num);
    }

    cout << min_num << endl;

    return 0;
}