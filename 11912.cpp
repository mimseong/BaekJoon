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

vector<int> v;

int calc(int d) {
    int ans = 0;

    for (int i = 0; i < v.size() && d >= 2; i++, d-=2) {
        ans += v[i];
    }

    return ans;
}

int main() {
    int n, k, d;
    scanf("%d %d %d", &n, &k, &d);

    vector<int> vp(k);
    for (int i = 0; i < k; i++)
        scanf("%d", &vp[i]);

    int front = vp[0] - 1;
    for (int i = 1; i < k; i++) {
        v.push_back(vp[i] - vp[i-1] - 1);
    }
    int back = n - vp[k-1];

    sort(all(v), greater<int>());

    // for (int i = 0; i < v.size(); i++)
    //     printf("%d ", v[i]);

    // 양 끝 숫자 안 쓰는 경우
    int ans = calc(d);

    // 왼쪽 끝을 쓰는 경우
    ans = max(ans, calc(d - 1) + front);

    // 오른쪽 끝을 쓰는 경우
    ans = max(ans, calc(d - 1) + back);

    // 양 끝 숫자 모두 쓰는 경우
    ans = max(ans, calc(d - 2) + back + front);

    printf("%d\n", ans);

    return 0;
}
