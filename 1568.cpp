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
    scanf("%lld\n", &n);
    
    vector<i64> v(50000);
    i64 count;
    for (int i = 1; v[i - 1] <= 1000000000; i++)
    {
        v[i] = i + v[i - 1];
        count = i;
    }
    
    int res = 0;
    for (int i = count - 1; n != 0; i--)
    {
        if (n < v[i])
            continue;
        n -= v[i];
        res += i;
        i++;
    }
    
    printf("%d\n", res);
    
    return 0;
}