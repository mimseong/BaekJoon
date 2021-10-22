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

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    vector<bitset<2005> > lamp(n);
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        
        for (int j = 0; j < num; j++) {
            int input;
            scanf("%d", &input);
            
            lamp[i][input] = 1;
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        bitset<2005> check;
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            
            check |= lamp[j];
        }
        
        bool isTrue = true;
        for (int i = 1; i <= m; i++) {
            if (check[i] == 0)
                isTrue = false;
        }
        
        if (isTrue) {
            ans = 1;
            break;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}