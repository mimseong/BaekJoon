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
#include <tuple>

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


int a, b;

bool is_cool(int n, int origin) {
    if (n < a || b < n || n <= origin || 2000000 < n)
        return false;

    string s = to_string(n);
    string origin_s = to_string(origin);
    if (s.size() != origin_s.size())
        return false;
    return true;
}

int cool_numbers(int n) {
    string origin = to_string(n);

    set<ii> s;
    for (int i = 0; i < origin.size() - 1; i++) {
        string cool = "";

        for (int j = i+1; j < origin.size(); j++) cool += origin[j];
        for (int j = 0; j <= i; j++) cool += origin[j];

        int coool = stoi(cool);

        // 멋진 쌍인지 확인
        if (!is_cool(coool, n)) continue;
        s.insert({n, coool});
    }
    return s.size();
}

int main() {
    scanf("%d %d", &a, &b);

    i64 ans = 0;
    for (int i = a; i <= b; i++) {
        // 멋진 숫자 쌍들을 기록
        ans += cool_numbers(i);
    }
    printf("%lld\n", ans);

    return 0;
}
