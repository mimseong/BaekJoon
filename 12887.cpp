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

int getCourseLen(int n, vector<string> &v, int start){
    if (v[start][0] == '#')
        return 99999999;
    
    
    int courseLen = 0;
    for (int i = 0, j = start; i < n; courseLen++) {
        if (v[j][i + 1] == '#') {
            j = (j + 1) % 2;
            continue;
        }
        i++;
    }
    
    return courseLen;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<string> v(2);
    for (int i = 0; i < 2; i++) {
        cin >> v[i];
        v[i] += ".";
    }
    
    int black = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            if (v[i][j] == '#')
                black++;
    
    int len1 = getCourseLen(n, v, 0);
    int len2 = getCourseLen(n, v, 1);
    
    
    cout << 2 * n - min(len1, len2) - black << "\n";
    
    return 0;
}