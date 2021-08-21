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

int main() {
     int n;
     scanf("%d", &n);
     
     vector<int> v(n);
     for (int i = 0; i < n - 1; i++) {
         int a, b;
         scanf("%d %d", &a, &b);
         
         v[a]++;
         v[b]++;
     }
     
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == 1)
            ans++;
    }
    
    cout << ans / 2 + ans % 2 << endl;
    return 0;
}