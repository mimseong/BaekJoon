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

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()
#define MAXV 1000000007

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

int arr[50];

int main() {
    string s, t;
    cin >> s >> t;
    
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < t.size(); j++) {
            if (t[j] == s[i] && j == 0)
                arr[j]++;
            else if (t[j] == s[i] && arr[j-1] > arr[j])
                arr[j]++;
        }
    }
    
    // for (int i = 0; i < t.size(); i++) {
    //     printf("%d ", arr[i]);
    // }
    
    printf("%d\n", arr[t.size() - 1]);
    
    return 0;
}