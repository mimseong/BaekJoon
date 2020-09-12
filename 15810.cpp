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
#pragma warning(disable:4996)
 
using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

i64 calc(i64 mid, int n, vector<int> a)
{
    i64 sum = 0;
    
    for (int i = 0; i < n; i++)
    {
        sum += mid / a[i];
    }
    
    return sum;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
        
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    i64 hi = 1000000000000;
    i64 lo = 1;
    
    for (int i = 0; i < 42; i++)
    {
        i64 mid = (hi + lo) / 2;
        
        if (calc(mid, n, a) < m)
            lo = mid;
        else
            hi = mid;
    }
    
    printf("%lld\n", hi);
    
    return 0;
}