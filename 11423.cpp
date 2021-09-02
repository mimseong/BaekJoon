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
 
bool check[10000005];
int sum[10000005];

int main() {
    for (int i = 2; i * i <= 10000005; i++)
    {
        if (check[i])
            continue ;
        
        for (int j = (i * 2); j <= 10000005 ; j += i)
            check[j] = true;
    }
    
    for (int i = 2; i <= 10000005; i++)
    {
        sum[i] += sum[i - 1];
        if (!check[i])
            sum[i] ++;
    }
    
    int n, m;
    while (cin >> n >> m) {
        cout << sum[m] - sum[n-1] << "\n\n";
    } 
    
    
    return 0;
}