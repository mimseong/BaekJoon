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
    
    if (n % 2 == 1) {
        printf("0\n");
        return 0;
    }
    
    if ((n / 2) % 2 == 1)
        printf("1\n");
    else
        printf("2\n");
    
            
    return 0;
}