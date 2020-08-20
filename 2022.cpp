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

double calc(double x, double y, double d)
{
    double h1 = sqrt(x*x - d*d);
    double h2 = sqrt(y*y - d*d);
    
    return h1*h2/(h1+h2);
}

int main() {
    double x, y, c;
    scanf("%lf %lf %lf", &x, &y, &c);
    
    double lo = 0.0, hi = min(x, y);
    
    for (int i = 0; i < 100; i++)
    {
        double mid = (lo + hi) * 0.5;
        
        if (calc(x, y, mid) < c)
            hi = mid;
        else
            lo = mid;
    }
    
    printf("%.6lf\n", lo);
    
    return 0;
}