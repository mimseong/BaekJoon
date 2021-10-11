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
    string s;
    cin >> s;
    
    int num = 0;
    int total = 0;
    for (int i = 0; i < s.size(); i++) {
        
        if (s[i] == '(' && s[i + 1] == ')') {
            total += num;
            i++;
            continue;
        }
        
        if (s[i] == '(')
            num++, total++;
        else
            num--;
    }
    
    printf("%d\n", total);

    return 0;
}