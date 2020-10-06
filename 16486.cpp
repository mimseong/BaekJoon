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
#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()
#pragma warning(disable:4996)
 
using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;
 
int main() {
    double d1, d2;
    scanf("%lf %lf", &d1, &d2);
    
    printf("%.6lf\n", d1 * 2 + 2 * 3.141592 * d2);
    
    return 0;
}