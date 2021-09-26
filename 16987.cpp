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

int s[15];
int w[15];
int n;

int solve(int start) {
    if (start == n) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] <= 0)
                cnt++;
        }
        return cnt;
    }
    
    if (s[start] <= 0)
        return solve(start + 1);
    
    int res = 0;
    bool isBreak = false;
    for (int i = 0; i < n; i++) {
        if (start == i || s[i] <= 0)
            continue;
        
        isBreak = true;
        s[start] -= w[i];
        s[i] -= w[start];
        
        res = max(res, solve(start + 1));
        
        s[start] += w[i];
        s[i] += w[start];
    }
    
    if (!isBreak)
        return solve(start + 1);
    return res;
}


int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &s[i], &w[i]);
    }
    
    cout << solve(0) << endl;
    
    return 0;
}