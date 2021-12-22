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
#include <stdio.h>
#include <math.h>
#include <sstream>

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
    int l, n;
    scanf("%d %d", &l, &n);
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    
    int minV = -1, maxV = -1;
    for (int i = 0; i < n; i++) {
        minV = max(minV, min(l - v[i], v[i]));
        maxV = max(maxV, max(l - v[i], v[i]));
    }
    
    printf("%d %d\n", minV, maxV);
}

int main() 
{
    int t;
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++) {
        solve();
    }
    
    return 0;
}