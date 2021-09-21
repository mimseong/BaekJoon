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
#define MOD 10007

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

int nCk[53][53];

int main() {
    int n;
    scanf("%d", &n);
    
    for (int n = 0; n <= 52; n++) {
        nCk[n][0] = 1; 
        nCk[n][n] = 1;
        for (int k = 1; k < n; k++) {
            nCk[n][k] = nCk[n-1][k-1] + nCk[n-1][k]; 
            nCk[n][k] %= MOD;
            nCk[n][n-k] = nCk[n][k];
        }
    }
    int ans = 0;
    for (int i = 4; i <= n; i += 4) {
        if ((i / 4) % 2 == 1)
            ans = (ans + nCk[13][i/4] * nCk[52 - i][n - i]) % MOD;
        else
            ans = (ans - nCk[13][i/4] * nCk[52 - i][n - i]) % MOD;
    }
    if (ans < 0)
        ans += MOD;
        
    printf("%d\n", ans);
    return 0;
}