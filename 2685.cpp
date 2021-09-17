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


void solve() {
    int b, x, y;
    scanf("%d %d %d", &b, &x, &y);
    
    queue<int> sX;
    do {
        sX.push(x % b);
    } while (x /= b);
    
    queue<int> sY;
    do {
        sY.push(y % b);
    } while (y /= b);
    
    int res = 0;
    int mul = 1;
    while (!sX.empty() && !sY.empty()) {
        res += (sX.front() + sY.front()) % b * mul;
        mul *= b;
        sX.pop();
        sY.pop();
    }
    
    while (!sX.empty()) {
        res += sX.front() * mul;
        mul *= b;
        sX.pop();
    }
    
    while (!sY.empty()) {
        res += sY.front() * mul;
        mul *= b;
        sY.pop();
    }
    
    cout << res << endl;
}


int main() {
    int t;
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++) {
        solve();
    }
    
    
    return 0;
}