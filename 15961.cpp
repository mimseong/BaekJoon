#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <cstring>
#include <map>
#define xx first
#define yy second
 
using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;


int main() 
{
    int n, d, k, c;
    scanf("%d %d %d %d", &n, &d, &k, &c);

    vector<int> v(n);
    vector<int> count (3005, 0);
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        count[v[i]]++;
        if (count[v[i]] == 1)
            sum++;
    }
    
    int ans = sum;
    if (count[c] == 0)
        ans = max(ans, sum + 1);
    else
        ans = max(ans, sum);

    int r = k-1;
    for (int l = 0; l < n;)
    {
        count[v[l]]--;
        if (count[v[l]] == 0)
        {
            sum--;
        }
        l++;
        
        r++;
        count[v[r%n]]++;
        if (count[v[r%n]] == 1)
        {
            sum++;
        }
        
        if (count[c] == 0)
            ans = max(ans, sum + 1);
        else
            ans = max(ans, sum);
        
    }

    cout << ans;
    
    return 0;
}