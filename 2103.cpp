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
#include <typeinfo>

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
    vector<int> vx[10005];
    vector<int> vy[10005];
    
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int inx, iny;
        
        scanf("%d %d", &inx, &iny);
        vx[inx].push_back(iny);
        vy[iny].push_back(inx);
    }
    
    int ans = 0;
    for (int i = 0; i <= 10000; i++) {
        sort(all(vx[i]));
        sort(all(vy[i]));
        
        for (int j = 0; j < vx[i].size(); j += 2) {
            ans += vx[i][j + 1] - vx[i][j];
        }
        for (int j = 0; j < vy[i].size(); j += 2) {
            ans += vy[i][j + 1] - vy[i][j];
        }
    }

    printf("%d\n", ans);
    return 0;
}