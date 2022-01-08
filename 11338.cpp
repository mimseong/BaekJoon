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
#include <stdio.h>
#include <math.h>
#include <sstream>

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

void solve() {
    int q, k;
    cin >> q >> k;
    
    priority_queue <int, vector<int>, greater<int> > pq;
    int sum = 0;
    
    for (int i = 0; i < q; i++) {
        string s;
        cin >> s;
            
        if (s == "print") {
            cout << sum << "\n";
            continue;    
        }
        
        int n;
        cin >> n;
        
        pq.push(n);
        sum ^= n;
        
        if (pq.size() > k) {
            sum ^= pq.top();
            pq.pop();
            continue;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    
    return 0;
}