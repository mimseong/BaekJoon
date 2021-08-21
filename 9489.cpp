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

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

void solve(int n, int k) {
    vector<int> v(n + 1, -1);
    vector<int> p(n + 1, -1);
    
    int idx, height = -1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        
        if (v[i] == k)
            idx = i;
        if (v[i] != v[i - 1] + 1)
            height++;
        p[i] = height;
    }
    
    int ans = 0;
    for (int i = 1; i<= n; i++) {
        if (p[i] != p[idx] && p[p[i]] == p[p[idx]])
            ans++;
    }
    
    printf("%d\n", ans);
}

int main() {
    
    while (true) {
        int n, k;
        scanf("%d %d", &n, &k);
        
        if (n == 0 && k == 0)
            break;
        
        solve(n, k);
    }
    
    
    
    return 0;
}