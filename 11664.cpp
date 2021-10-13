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

int main() {
    double ax, ay, az, bx, by, bz, cx, cy, cz;
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf", &ax, &ay, &az, &bx, &by, &bz, &cx, &cy, &cz);
    
    double mid1, mid2;
    for (int i = 0; i < 1000000; i++) {
        // 3등분 점을 구한다
        double x1 = ax + (bx - ax)/3;
        double x2 = ax + 2 * (bx - ax)/3;
        double y1 = ay + (by - ay)/3;
        double y2 = ay + 2 * (by - ay)/3;
        double z1 = az + (bz - az)/3;
        double z2 = az + 2 * (bz - az)/3;
        
        mid1 = (x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy) + (z1 - cz) * (z1 - cz);
        mid2 = (x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy) + (z2 - cz) * (z2 - cz);
        
        if (mid1 < mid2) {
            bx = x2;
            by = y2;
            bz = z2;
        }
        else {
            ax = x1;
            ay = y1;
            az = z1;
        }
    }
    
    printf("%.9lf", min(sqrt(mid1), sqrt(mid2)));
    
    return 0;
}