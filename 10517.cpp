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

struct Point {
    double x, y;
};

Point circumcenter(double x1,double y1,double x2,double y2,double x3,double y3) {
    double A = x1 * (y2 - y3) - y1 * (x2 - x3) + x2 * y3 - y2 * x3;
    double B = (pow(x1, 2) + pow(y1, 2)) * (y3 - y2) + (pow(x2, 2) + pow(y2, 2)) * (y1 - y3) + (pow(x3, 2) + pow(y3, 2)) * (y2 - y1);
    double C = (pow(x1, 2) + pow(y1, 2)) * (x2 - x3) + (pow(x2, 2) + pow(y2, 2)) * (x3 - x1) + (pow(x3, 2) + pow(y3, 2)) * (x1 - x2);
    double x = -B / (2 * A);
    double y = -C / (2 * A);
    return {x, y};
}

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

bool is_obtuse(double a, double b, double c) {
    double cos_a = (b*b + c*c - a*a) / (2*b*c);
    double cos_b = (c*c + a*a - b*b) / (2*a*c);
    double cos_c = (a*a + b*b - c*c) / (2*a*b);
    return cos_a < 0 || cos_b < 0 || cos_c < 0;
}

bool is_obtuse(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a = distance(x1, y1, x2, y2);
    double b = distance(x2, y2, x3, y3);
    double c = distance(x3, y3, x1, y1);
    return is_obtuse(a, b, c);
}

void solve(int case_num) {
    printf("Case #%d: ", case_num);
    
    
    double x1, y1, x2, y2, x3, y3;
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);

    if (is_obtuse(x1, y1, x2, y2, x3, y3)) {
        // 둔각일 경우
        double a = distance(x1, y1, x2, y2);
        double b = distance(x2, y2, x3, y3);
        double c = distance(x3, y3, x1, y1);
        
        // 가장 긴 길이 선분의 중간 점
        if (a > b && a > c) {
            printf("%.2lf %.2lf\n", (x1 + x2) / 2, (y1 + y2) / 2);
        } else if (b > a && b > c) {
            printf("%.2lf %.2lf\n", (x2 + x3) / 2, (y2 + y3) / 2);
        } else {
            printf("%.2lf %.2lf\n", (x3 + x1) / 2, (y3 + y1) / 2);
        }
        
        
    } else {
        // 직각이거나 예각인 경우
        // 외심을 구한다
        Point center = circumcenter(x1, y1, x2, y2, x3, y3);
        printf("%.2lf %.2lf\n", center.x, center.y);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
    
    return 0;
}
