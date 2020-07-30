#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()
 
using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;


int main() {
    double a, b;
    double c = 299792458;
    
    while (cin >> a >> b)
    {
        if (a == 0 && b == 0)
            break ;
            
        double tmp = 1 - (b/a)*(b/a);
        
        printf("%.3lf\n", sqrt(tmp));
    }
    
    return 0;
}