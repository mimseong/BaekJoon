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

void hanoi(int n, int from, int middle, int to) {
    if (n == 1) {
        cout << from << " " << to << "\n";
        return;
    }
    hanoi(n - 1, from, to, middle);
    cout << from << " " << to << "\n";
    hanoi(n - 1, middle, from, to);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int k;
    cin >> k;
    
    string s = to_string(pow(2, k));
    s = s.substr(0, s.find("."));
    
    s[s.size() - 1] -= 1;
    
    cout << s << "\n";
    
    if (k <= 20)
        hanoi(k, 1, 2, 3);
    
    return 0;
}