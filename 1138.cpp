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
    int n;
    scanf("%d", &n);
    
    // 자리가 찾는지 기록하는 벡터
    vector<int> v(n + 1); 
    for (int i = 0; i < n; i++) {
        int in;
        scanf("%d", &in);
        
        int bigger = 0;
        for (int j = 0; j < n; j++) {
            if (v[j] == 0)
                bigger++;
            
            if (bigger == in) {
                in = j + 1;
                break;
            }
        }
        
        while (in < n) {
            if (v[in] == 0) {
                v[in] = i + 1;
                break;
            }
            in++;
        }
    }
    
    for (int i = 0; i < n; i++) 
        printf("%d ", v[i]);
    
    return 0;
}