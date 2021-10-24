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
#include <typeinfo>

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

int getWeight(char c) {
    if (c == 'H')
        return 1;
    if (c == 'C')
        return 12;
    if (c == 'O')
        return 16;
    return 0;
}

int main() {
    string s;
    cin >> s;
    
    stack<int> st;
    st.push(0);
    int tmp = 0;
    for (int i = 0; i < s.size(); i++) {
        
        if (s[i] == 'C' || s[i] == 'H' || s[i] == 'O') {
            tmp = getWeight(s[i]);
            
            int tp = st.top();
            st.pop();
            st.push(tp + tmp);
        }
        else if (s[i] == '(')
            st.push(0);
        else if (s[i] == ')') {
            tmp = st.top();
            st.pop();
            
            int tp = st.top();
            st.pop();
            st.push(tp + tmp);
        }
        else{
            int tp = st.top();
            st.pop();
            st.push(tp + tmp * (s[i] - '1'));
        }
    }
    
    cout << st.top();
    
    return 0;
}