#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <deque>
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
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;
 
int main() {
    int n;
    scanf("%d", &n);
    
    vector<i64> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &v[i]);
    }
    
    sort(all(v));

    i64 ans;
    if (n % 2 == 0) {
        ans = v[0] + v[n - 1];
        for (int i = 0; i < n / 2; i++) {
            ans = max(ans, v[i] + v[n - 1 - i]);
        }
    }
    else {
        ans = v[n - 1];
        for (int i = 1; i < n / 2; i++) {
            ans = max(ans, v[i] + v[n - 2 - i]);
        }
    }
    printf("%lld", ans);
    
    
    return 0;
}