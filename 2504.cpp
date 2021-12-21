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

int main() {
    string s;
    cin >> s;
    
    // 올바른 식인지 확인하기
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if ((st.empty() && (s[i] == ')' || s[i] == ']')) ||
            (s[i] == ')' && st.top() != '(') || 
            (s[i] == ']' && st.top() != '[')) {
            printf("0\n");
            return 0;
        }
        
        if (s[i] == '(' || s[i] == '[')
            st.push(s[i]);
        else
            st.pop();
    }
    
    if (!st.empty()) {
        printf("0\n");
        return 0;
    }
    
    i64 tmp = 1;
    i64 ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            tmp *= 2;
        else if (s[i] == '[')
            tmp *= 3;
        else if (s[i] == ')') {
            if (s[i - 1] == '(')
                ans += tmp;
            tmp /= 2;
        }
        else if (s[i] == ']') {
            if (s[i - 1] == '[')
                ans += tmp;
            tmp /= 3;
        }  
    }
    
    cout << ans << "\n";
    
    
    return 0;
}