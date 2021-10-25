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

int n;
int v[305];
int dp[305][5];

int func(int idx, int len) {
    if (idx >= n)
        return -1000000000;
    
    if (idx == n - 1)
        return v[idx];
    
    if (dp[idx][len] != 0)
        return dp[idx][len];
    
    int a = -1000000000, b = -1000000000;
    
    if (len == 1)
        a = func(idx + 1, len + 1);
    b = func(idx + 2, 1);
    
    return dp[idx][len] = max(a, b) + v[idx];
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    
    
    printf("%d\n", max(func(0, 1), func(1, 1)));

    return 0;
}