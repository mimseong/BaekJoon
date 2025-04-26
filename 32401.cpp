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
#include <cassert>
#include <climits>
#include <tuple>

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()
#define MAXV 987654321
#define FOR(i, n) for (int i = 0; i < (n); ++i)

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;


int main() {
    int n;
    scanf("%d", &n);
    
    string s;
    cin >> s;
    
    int state = 0;
    int ans = 0;
    FOR (i, s.size()) {
        if (s[i] == 'A' && state == 0)
            state = 1;
        else if (s[i] == 'N' && state == 1)
            state = 2;
        else if (s[i] == 'A' && state == 2) {
            ans++;
            state = 1;
        }
        else if (s[i] == 'A' && state == 1)
            state = 1;
        else if (s[i] == 'N' && state == 2)
            state = 0;
        // printf("%d\n", state);
    }
    
    printf("%d\n", ans);
    
    return 0;
}