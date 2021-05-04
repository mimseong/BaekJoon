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

bool    check(vector<int> &v) {
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i] != v[i+1])
            return false;
    }
    return true;
}

void    printv(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void    solve(int n, int m) {
    vector<int> v(n);
    int start = 0;
    
    while(true) {
        for (int i = 0; i < m; i++) {
            v[(i + start) % v.size()]++;
        }
        
        int r = m % v.size();
        if (r == 0)
            r = v.size();
        
        v.erase(v.begin() + (start + r - 1) % v.size());
        start = (start + r - 1) % (v.size() + 1);
        
        if (start == v.size())
            start = 0;
        
        
        if(check(v))
            break;
    }
    
    printf("%d %d\n", v.size(), v[0]);
}

int main() {
    int n, m;
    
    while (1) {
        scanf("%d", &n);
        if (n == 0)
            break;
        scanf("%d", &m);
        
        solve(n, m);
    }
    
    return 0;
}