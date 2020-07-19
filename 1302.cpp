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
 
using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;
 
int main() {
    int n;
    scanf("%d", &n);
    vector<string> v(n);
    
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    string bef = v[0];
    int max = 0;
    int count = 1;
    string ans = v[0];
    for (int i = 1; i < n; i++)
    {
        if (bef != v[i])
        {
            if (max < count)
            {
                max = count;
                ans = bef;
            }
            count = 1;
        }
        else
        {
            count++;
        }
        bef = v[i];
    }
    if (max < count)
        ans = bef;
    
    cout << ans;
    
    return 0;
}