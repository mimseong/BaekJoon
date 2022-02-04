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

i64 dp[55][55][55];

i64 w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    
    auto& res = dp[a][b][c];
    
    if (res != -1)
        return res;
    if (a > 20 || b > 20 || c > 20)
        return res = w(20, 20, 20);
    if (a < b && b < c)
        return res = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    return res = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}

int main() {
    memset(dp, -1, sizeof(dp));
    
    while (true) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        
        if (a == -1 && b == -1 && c == -1)
            break;
        
        int ans = w(a, b, c);
        printf("w(%d, %d, %d) = %d\n", a, b, c, ans);
    }
    
    return 0;
}