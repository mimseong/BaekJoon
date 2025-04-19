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
#define MAXV 1000000007

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;


int n;
i64 dp[200050][10];

i64 solve(int day, int today) {
    if (dp[day][today] != -1)
        return dp[day][today];

    auto& res = dp[day][today];

    if (n <= day)
        return 1;

    i64 ans = 0;
    if (today != 0) // 오늘 식당을 갔다면
        ans += solve(day + 1, 0) % MAXV; // 내일 굶어도 된다

    if (today == 1) { // 오늘 1번 식당을 갔다면
        ans += solve(day + 1, 3) % MAXV;
        ans += solve(day + 1, 4) % MAXV;
    }
    else if (today == 2) { // 오늘 2번 식당을 갔다면
        ans += solve(day + 1, 4) % MAXV;
    }
    else if (today == 3) { // 오늘 3번 식당을 갔다면
        ans += solve(day + 1, 1) % MAXV;
    }
    else if (today == 4) { // 오늘 4번 식당을 갔다면
        ans += solve(day + 1, 1) % MAXV;
        ans += solve(day + 1, 2) % MAXV;
    }
    else { // 오늘 굶었다면
        // 내일 식당에 가서 밥을 먹어야 한다
        ans += solve(day + 1, 1) % MAXV;
        ans += solve(day + 1, 2) % MAXV;
        ans += solve(day + 1, 3) % MAXV;
        ans += solve(day + 1, 4) % MAXV;
    }

    return res = ans % MAXV;
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);

    i64 ans = 0;
    for (int i = 0; i <= 4; i++) {
        // 첫날에는 굶거나 임의로 원하는 식당 하나를 골라서 간다
        ans += solve(1, i) % MAXV;
    }

    printf("%lld\n", ans % MAXV);

    return 0;
}
