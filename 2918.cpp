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

int check[2005][2005];

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

int main() {
    int n;
    scanf("%d", &n);
    
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    sort(all(v));
    
    int g = v[1] - v[0];
    for (int i = 2; i < n; i++) {
        g = gcd(g, v[i] - v[i - 1]);
    }
    
    vector<int> ans;
    for (int i = 1; i*i <= g; i++)
    {
        if (g % i != 0)
            continue;
        if (i*i != g)
            ans.push_back(i);
        ans.push_back(g / i);
    }
    sort(all(ans));
    
    for (int i = 1; i < ans.size(); i++)
        printf("%d ", ans[i]);
    
    
    
    return 0;
}