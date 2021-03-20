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

i64 calc[1000005];
i64 sum[1000005];

int main() {
    for (i64 i = 1; i <= 1000000; i++)
    {
        for (i64 j = 1; j * i <= 1000000; j++)
        {
            calc[i * j] += i;
        }
    }
    
    for (int i = 1; i <= 1000000; i++)
    {
        sum[i] += sum[i - 1] + calc[i];
    }
    
    i64 t;
    scanf("%lld", &t);
    
    for (int i = 0; i < t; i++)
    {
        i64 n;
        scanf("%lld", &n);
        
        printf("%lld\n", sum[n]);
    }
    
    
    
    
    return 0;
}