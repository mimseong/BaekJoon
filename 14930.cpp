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

int main() {
    i64 n, t;
    scanf("%lld %lld", &n, &t);
    
    vector<ii64> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &v[i].xx, &v[i].yy);
    }
    
    // 빨간 구슬의 순번 k를 구함
    i64 redX = v[0].xx;
    i64 k;
    sort(all(v));
    for (int i = 0; i < n; i++) {
        if (v[i].xx == redX)
            k = i;
    }
    
    // x + v * t 기준으로 정렬
    for (int i = 0; i < n; i++) {
        v[i].xx = v[i].xx + v[i].yy * t;
    }
    
    sort(all(v));
    
    
    // k번째를 구함
    printf("%lld", v[k].xx);
    
    return 0;
}