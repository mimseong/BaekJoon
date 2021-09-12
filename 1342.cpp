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
 
int ans;
char alpha[26];

void solve(int now, string s, int n) {
    if (now == n) {
        ans++;
        return;
    }
    
    for (int i = 0; i < 26; i++) {
        if (alpha[i] <= 0)
            continue;
        
        if (s.size() == 0 || s[s.size() - 1] != i + 'a') {
            alpha[i]--;
            solve(now + 1, s + (char)(i + 'a'), n);    
            alpha[i]++;
        }
    }
}
 
int main() {
    string s;
    cin >> s;
    
    for (int i = 0; i < s.size(); i++) {
        alpha[s[i] - 'a']++;
    }
    
    solve(0, "", s.size());
    
    cout << ans << "\n";
    
    return 0;
}