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
#define MAXV 987654321

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

pair<double, double> pointOfIntersection(double a1, double b1, double c1, double a2, double b2, double c2) {
    double x;
    double y;
    if (b1 == 0) {
        x = (b2*c1 - b1*c2) / (a2*b1 - a1*b2);
        y = -1 * (a2/b2) * x - c2/b2;
    }
    else {
        x = (b1*c2 - b2*c1) / (a1*b2 - a2*b1);
        y = -1 * (a1/b1) * x - c1/b1;
    }

    pair<double, double> ans(x, y);
    return ans;
}

bool isParallel(double a1, double b1, double a2, double b2) {
    if (a1*b2 - a2*b1 == 0)
        return true;
    return false;
}

double widthOfTriangle(double x1, double x2, double x3, double y1, double y2, double y3) {
    double a = x1*y2 + x2*y3 + x3*y1;
    double b = x2*y1 + x3*y2 + x1*y3;
    return 0.5 * abs(a - b);
}

void solve() {
    double a1, b1, c1;
    double a2, b2, c2;
    double a3, b3, c3;

    scanf("%lf %lf %lf", &a1, &b1, &c1);
    scanf("%lf %lf %lf", &a2, &b2, &c2);
    scanf("%lf %lf %lf", &a3, &b3, &c3);

    if (isParallel(a1, b1, a2, b2) || isParallel(a1, b1, a3, b3) || isParallel(a3, b3, a2, b2)) {
        printf("0.0000\n");
        return;
    }

    pair<double, double> p1 = pointOfIntersection(a1, b1, c1, a2, b2, c2);
    pair<double, double> p2 = pointOfIntersection(a1, b1, c1, a3, b3, c3);
    pair<double, double> p3 = pointOfIntersection(a3, b3, c3, a2, b2, c2);

    if (p1 == p2 && p2 == p3) {
        printf("0.0000\n");
        return;
    }

    printf("%.4lf\n", widthOfTriangle(p1.xx, p2.xx, p3.xx, p1.yy, p2.yy, p3.yy));
}

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}
