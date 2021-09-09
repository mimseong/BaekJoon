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
    
    int x, y;
    scanf("%d %d", &x, &y);

    set<ii> s;
    vector<ii> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &v[i].xx, &v[i].yy);
        
        s.emplace(v[i].xx, v[i].yy);
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a = v[i].xx, b = v[i].yy;
        
        if (s.find({a + x, b}) == s.end())
            continue;
        if (s.find({a + x, b + y}) == s.end())
            continue;
        if (s.find({a, b + y}) == s.end())
            continue;
        ans++;
    }
    cout << ans << endl;
    return 0;
}