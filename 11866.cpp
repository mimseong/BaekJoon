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
        v[i] = i + 1;

    k--;
    int count = 0;
    vector<int> ans;
    while (!v.empty())
    {
        count = (count + k) % v.size();
        ans.push_back(v[count]);
        v.erase(v.begin() + count);
    }

    printf("<");
    for (int i = 0; i < ans.size() - 1; i++)
        printf("%d, ", ans[i]);
    printf("%d>", ans[ans.size() - 1]);

    return 0;
}