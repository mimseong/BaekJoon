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

int n;
int w[20][20];
int dp[20][1<<16];

int tsp(int curr, int visited) {
    int &ret = dp[curr][visited];
    if (ret != -1) return ret;

    // 모든 비트가 1인 경우 (모든 마을을 방문함)
    if (visited == (1<<n) - 1) {
        if (w[curr][0] != 0) return w[curr][0];
        // 시작점으로 갈 수 없는 경우 - 불가능
        return 1000000000;
    }

    ret = 1000000000;
    for (int i = 0; i < n; i++) {
        // i번 마을을 이미 방문했거나 i번 마을로 갈 수 없음
        if (visited & (1 << i) || w[curr][i] == 0) continue;
        // 그 외 경우
        // visited | (1 << i): i번 비트를 1로 만들었다
        ret = min(ret, tsp(i, visited | (1 << i)) + w[curr][i]);
    }
    return ret;
}


int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &w[i][j]);
        }
    }

    memset(dp, -1, sizeof(dp));
    // 0번부터 방문, 0번 방문해서 0000001 (0번째 자리가 1)
    printf("%d\n", tsp(0, 1));

    return 0;
}
