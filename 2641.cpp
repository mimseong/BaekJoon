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

int n;

void solve(string &s1, string &s2, vector<string> &ans) {
    string s = "";
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        s += (tmp + '0');
    }
    
    if (s1.find(s) != string::npos) {
        ans.push_back(s);
	}
	else if (s2.find(s) != string::npos) {
	    ans.push_back(s);
	}
}

int main() {
    scanf("%d", &n);
    
    string s1 = "";
   
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        s1 += (tmp + '0');
    }
    
    string s2 = "";
    for (int i = n-1; i >= 0; i--) {
        if (s1[i] == '1')
            s2 += '3';
        else if (s1[i] == '3')
            s2 += '1';
        else if (s1[i] == '2')
            s2 += '4';
        else if (s1[i] == '4')
            s2 += '2';
    }
    
    s1 += s1;
    s2 += s2;
    
    int m;
    scanf("%d", &m);
    vector<string> v;
    for (int i = 0; i < m; i++) {
        solve(s1, s2, v);
    }
    
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++)
            cout << v[i][j] << " ";
        cout << "\n";
    }
    
    
    return 0;
}