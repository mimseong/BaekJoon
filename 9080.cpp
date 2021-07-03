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
 
void solve() {
    int hh, mm, d;
    scanf("%d:%d %d", &hh, &mm, &d);
    
    int ans = 0;
    while (d > 0) {
        // cout << ans << endl;
        if ((hh < 3 || 22 <= hh) && d > 5 * 60) {
            int left;
            if (22 <= hh) {
                left = 10 * 60 - ((hh - 22) * 60 + mm);
            } else {
                left = 8 * 60 - (hh * 60 + mm);
            }
            d -= left;
            hh = 8;
            mm = 0;
            ans += 5000;
            continue;
        }
        hh = (hh + 1) % 24;
        d -= 60;
        ans += 1000;
    }
    
    printf("%d\n", ans);
}
 
int main() {
    int t;
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++) {
        solve();
    }
    
    
    return 0;
}