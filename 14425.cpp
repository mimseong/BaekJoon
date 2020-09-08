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
 
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    
    
    map<string, bool> mp;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        mp[str] = true;
    }
        
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        
        if (mp[str])
            cnt++;
    }
    
    cout << cnt << "\n";
    
    return 0;
}