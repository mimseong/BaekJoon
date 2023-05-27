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

int n, w, t, k;
i64 ans = 0;
int v[10];
bool start = true;

void solve(int pos, int time) {
    vector<int> decrease(10);

    // 화력 감소
    for (int i = 0; i < n; i++) {
        if (i == pos && !start)
            continue;

        int cnt = 0;
        if (0 < i) {
            cnt += (v[i - 1] > 0);
        }
        if (i < n - 1) {
            cnt += (v[i + 1] > 0);
        }

        if (cnt == 0) {
			decrease[i] = 3;
		}
		else if (cnt == 1) {
			decrease[i] = 2;
		}
		else if (cnt == 2) {
			decrease[i] = 1;
		}
    }
    for (int i = 0; i < n; i++)
        v[i] -= decrease[i];


    start = false;

    // time이 t라면 놀이 종료
    if (time == t) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] > 0) cnt++;
        }
        if (cnt >= k)
            ans++;
        for (int i = 0; i < n; i++)
            v[i] += decrease[i];
        return;
    }

    // 왼쪽으로 이동
    if (0 < pos) {
        solve(pos - 1, time + 1);
    }

    // 오른쪽으로 이동
    if (pos < n - 1) {
        solve(pos + 1, time + 1);
    }

    // 현위치에 장작 넣음
    solve(pos, time + 1);

    for (int i = 0; i < n; i++)
        v[i] += decrease[i];
}

int main() {
    scanf("%d %d %d %d", &n, &w, &t, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    solve(w, 1);
    printf("%lld\n", ans);

    return 0;
}
