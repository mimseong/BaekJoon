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
 
int main() {
    i64 n;
    scanf("%lld", &n);
    
    i64 l = 1;
    i64 r = n - 1;
    i64 calc = (n * (n - 1) / 2 + 1) / 2;
    // printf("calc : %d\n", calc);
    
    while (l <= r) {
        i64 mid = (l + r) / 2;
        
        i64 start = (mid - 1) * n  - (mid - 1) * mid / 2 + 1;
        i64 end = start + (n - mid) - 1;
        
        // printf("l : %d r : %d mid :%d start: %d, end: %d\n", l, r, mid, start, end);
        
        if (calc < start)
            r = mid;
        else if (end < calc)
            l = mid;
        else {
            printf("%lld\n", mid);
            return 0;
        }
    }
    printf("%lld\n", l);
    
    return 0;
}