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
    int n;
    scanf("%d", &n);
    
    vector<int> v(n);
    vector<int> dp(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
        
    int max = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == 0)
            dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j])
            {
                if (dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
            }
        }
        
        if (max < dp[i])
            max = dp[i];
    }
    
    cout << max;
    
    return 0;
}