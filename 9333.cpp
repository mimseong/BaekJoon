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

void solve() {
    // r: 이자 퍼센트, b: 빌린 돈, m: 과외비
    double r, b, m;
    scanf("%lf %lf %lf", &r, &b, &m);

    b *= 100;
    m *= 100;
    double remain = b;
    // printf("시작 금액: %lf\n", b);

    for (int i = 1; i <= 1200; i++) {
        // 이자가 붙음
        remain *= 1 + r / 100;
        remain = round(remain);
        // printf("이자 붙음: %lf\n", remain);

        // 과외비 M달러를 갚음
        remain -= m;
        remain = round(remain);
        // printf("과외비 갚음: %lf\n", remain);

        // 갚은 돈이 이자를 못 따라가는 상황
        // 글렀음
        if (b < remain) break;

        if (remain <= 0) {
            printf("%d\n", i);
            return;
        }
    }

    printf("impossible\n");
}

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}
