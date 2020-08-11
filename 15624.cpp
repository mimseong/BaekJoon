#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()
 
using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;
 
int main() {
    i64 n;
    scanf("%lld", &n);
    
    vector<i64> v(n+1);
    v[0] = 0;
    v[1] = 1;
    
    for (int i = 2; i <= n; i++)
        v[i] = (v[i-1] + v[i-2]) % 1000000007;
    
    printf("%lld\n", v[n]);
    
    return 0;
}