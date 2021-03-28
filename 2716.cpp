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

i64 two[80];

void solve() {
    string s;
    getline(cin, s);
    
    if (s == "")
    {
        cout << "1\n";
        return;
    }
    
    stack<char> st;
    int maxv = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '[')
        {
            st.push('[');
            continue;
        }
        maxv = max(maxv, (int)st.size());
        st.pop();
    }
    
    cout << two[maxv] << "\n";
    
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    cin.ignore();
    
    two[0] = 1;
    for (int i = 1; i < 80; i++)
        two[i] = two[i-1] * 2;
    
    for (int i = 0; i < n; i++)
        solve();
    
    return 0;
}