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

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    
    sort(all(v));
    
    for (int j = 0; j < m; j++) {
        int x1, x2;
        scanf("%d %d", &x1, &x2);
        
        printf("%d\n", upper_bound(all(v), x2) - lower_bound(all(v), x1));
        
    }

    return 0;
}