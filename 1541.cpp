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

vector<string> split(string s, string delimiter) {
    vector<string> v;
    
    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        
        if (token != "")
            v.push_back(token);
        
        s.erase(0, pos + delimiter.length());
    }
    if (token != "")
        v.push_back(s);
    
    return v;
}

int main() {
    string s;
    cin >> s;
    
    vector<char> op;
    for (int i = 0; i < s.size(); i++) {
        if ('0' <= s[i] && s[i] <= '9')
            continue;
        op.push_back(s[i]);
    }
    
    vector<string> v = split(s, "+");
    if (v.empty())
        v.push_back(s);
    vector<int> numberVector;
    for (int i = 0; i < v.size(); i++) {
        vector<string> res = split(v[i], "-");
        if (res.empty()) {
            numberVector.push_back(stoi(v[i]));
        } else {
            for (int j = 0; j < res.size(); j++) {
                numberVector.push_back(stoi(res[j]));
            }
        }
    }
    
    int left = numberVector[0];
    int minusTmp = 0;
    bool isMinus = false;
    for (int i = 1; i < numberVector.size(); i++) {
        if (op[i-1] == '-') {
            if (isMinus) {
                left -= minusTmp;
                minusTmp = numberVector[i];
            } else {
                minusTmp += numberVector[i];
            }
            isMinus = true;
        } else {
            if (isMinus) {
                minusTmp += numberVector[i];
            } else {
                left += numberVector[i];
            }
        }
    }
    // printf("%d %d\n", left, minusTmp);
    left -= minusTmp;
    
    printf("%d", left);
    
    return 0;
}