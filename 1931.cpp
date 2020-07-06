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
#define xx first
#define yy second
#define MAX 1e9
#define all(x) (x).begin(), (x).end()
 
using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

bool sortbysecond(const ii64 &a, const ii64 &b)
{
    if (a.second == b.second)
        return a.xx < b.xx;
    else
        return (a.yy < b.yy);
}

int main() {
    int n;
    scanf("%d", &n);
    
    vector<ii64> v(n);
    for (int i = 0; i < n; i++)
        scanf("%lld %lld", &v[i].first, &v[i].second);

    sort(all(v), sortbysecond);

    int end = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i].xx >= end)
        {
            end = v[i].yy;
            ans++;
        }
    }
    
    printf("%d\n", ans);
    return 0;
}