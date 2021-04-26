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
 
int main() {
    int n;
    scanf("%d", &n);
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        
        string res = "";
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '0' || s[j] == '6')
                res += '9';
            else
                res += s[j];
        }
        sum += min(100, stoi(res));
    }
    cout << round((double)sum / n);
    
    return 0;
}