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

int v[20][5];

int main() {
    int n;
    scanf("%d", &n);

    int mp, mf, ms, mv;
    scanf("%d %d %d %d", &mp, &mf, &ms, &mv);

    vector<int> price(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d %d", &v[i][0], &v[i][1], &v[i][2], &v[i][3], &price[i]);
    }


    // do someting.......
    vector<int> ans = {100, 100, 100, 100};
    int minv = MAXV;

    for (int i = 0; i < (1 << n); i++) {
        // 아무것도 선택하지 않는 경우
        if (i == 0) continue;

        int p = 0, f = 0, s = 0, vv = 0;

        vector<int> numbers;
        int sumv = 0;
        for (int j = 0; j < n; j++) {
            // j번 식재료를 사용하겠다
            if (i & (1 << j)) {
                numbers.push_back(j);
                p += v[j][0]; f += v[j][1]; s += v[j][2]; vv += v[j][3];
                sumv += price[j];
            }
        }

        // 영양분 조건을 만족하는지 확인 && 가격이 최소보다 작으면
        if (p >= mp && f >= mf && s >= ms && vv >= mv) {
            if (minv > sumv) {
                ans = numbers;
                minv = sumv;
            } else if (minv == sumv && ans > numbers) {
                ans = numbers;
                minv = sumv;
            }
        }
    }

    if (minv == MAXV) {
        printf("-1\n");
        return 0;
    }

    printf("%d\n", minv);
    for (int i = 0; i < ans.size(); i++)
        printf("%d ", ans[i] + 1);

    return 0;
}
