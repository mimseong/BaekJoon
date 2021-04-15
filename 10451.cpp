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

void dfs(vector<int> &v, vector<bool> &visited, int start) {
    if (visited[start])
        return;
    visited[start] = true;
    dfs(v, visited, v[start]);
}

void solve() {
    int n;
    scanf("%d", &n);
    
    vector<int> v(n + 1);
    vector<bool> visited(n + 1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i])
            continue;
        
        ans++;
        dfs(v, visited, v[i]);
    }
    
    cout << ans << endl;
} 

int main() {
    int t;
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++) {
        solve();
    }
    
    
    return 0;
}