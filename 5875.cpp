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
#include<cassert>
#include <climits>
#include <tuple>

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()
#define MAXV 987654321

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

int main() {
    string s;
    cin >> s;

    int left = 0, right = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            left++;
        else
            right++;
    }

    if (left == right) {
        printf("0\n");
        return 0;
    }

    string revertString = "";
    if (right < left) {
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(')
                revertString += ')';
            else
                revertString += '(';
        }

        s = revertString;
        int tmp = left;
        left = right;
        right = tmp;
    }

    // cout << s << "\n" << left << " " << right << "\n";

    stack<char> st;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push('(');
            continue;
        }

        ans++;
        if (st.size() == 0)
            break;
        st.pop();
    }

    printf("%d\n", ans);

    return 0;
}
