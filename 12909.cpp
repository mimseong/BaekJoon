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
#include<cassert>
#include <climits>

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()
#define MAXV 987654321

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

int score[55];
int dp[55][55];

int solve(int node, int edge) {
    if (node == 1)
        return score[edge];

    int &ret = dp[node][edge];
    if (ret != -1)
        return ret;
    
    ret = 0;
    for (int i = 1; i < node; i++)
        ret = max(ret, solve(i, 1) + solve(node - i, edge + 1));
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 1; i < n; i++) {
        scanf("%d", &score[i]);
    }
    
    memset(dp, -1, sizeof(dp));
    
    printf("%d\n", solve(n, 0));
    
    return 0;
}
