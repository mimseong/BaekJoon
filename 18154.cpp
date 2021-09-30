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
    
    
    vector<ii> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &v[i].xx, &v[i].yy);
    }
    
    int maxv = 0;
    for (int i = 1; i < n; i++) {
        maxv = max(maxv, (v[i].yy - v[i-1].yy) / (v[i].xx - v[i-1].xx));
    }
    
    printf("%d", maxv);
    return 0;
}