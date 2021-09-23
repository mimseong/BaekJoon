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
    i64 a, b;
    scanf("%lld %lld", &a, &b);
    
    i64 sum = 0;
    for (int k = 1; k <= 1000000; k++) {
        for (i64 j = ((a + k - 1) / k) * k ; j <= b; j += k) {
            sum += k;
            if (j / k > 1000000)
                sum += j / k;
        }
    }
    
    cout << sum << endl;
    
    return 0;
}