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

int arr[30][200005];

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    string s;
    cin >> s;
    // cout << s << "\n";
    
    for (char alpha = 'a'; alpha <= 'z'; alpha++) {
        for (int j = 0; j < s.size(); j++) {
            if (alpha == s[j])
                arr[alpha - 'a'][j]++;
            if (j == 0)
                continue;
            arr[alpha - 'a'][j] += arr[alpha - 'a'][j - 1];
        }
    }
    
    // for (char alpha = 'a'; alpha <= 'z'; alpha++) {
    //     for (int j = 0; j < s.size(); j++) {
    //         printf("%d ",  arr[alpha - 'a'][j]);
    //     }
    //     printf("\n");
    // }

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int idx1, idx2;
        char c;
        
        cin >> c >> idx1 >> idx2;
        
        int n1 = (idx1 == 0) ? 0 : arr[c - 'a'][idx1 - 1];
        int n2 = arr[c - 'a'][idx2];
        
        // cout << c << " " << n1 << " " << n2 << "\n";
        cout << n2 - n1 << "\n";
    }
    
    return 0;
}