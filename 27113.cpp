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
#define FOR(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;



int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // 나의 위치 x
    int x = 1;
    FOR(i, n-1) {
        int a;
        scanf("%d", &a);

        if (a == 0) continue;

        vector<pair<int, char>> v(a);
        FOR(i, a) {
            scanf("%d %c", &v[i].xx, &v[i].yy);
            if (v[i].yy == 'L') v[i].xx += 1;
            else v[i].xx -= 1;
        }

        if (a == 1) {
            if (v[0].yy == 'L') x = max(x, v[0].xx);
            else {
                if (v[0].xx < x) {
                    printf("NO\n");
                    return 0;
                }
            }
            continue;
        }

        if (v[0].yy == 'R' && v[1].yy == 'L') {
            if (v[0].xx < x) x = max(x, v[1].xx);
            continue;
        }

        for (auto& vi: v) {
            if (vi.yy == 'L') x = max(x, vi.xx);
            else {
                if (vi.xx < x) {
                    printf("NO\n");
                    return 0;
                }
            }
        }
    }

    if (m < x) printf("NO\n");
    else printf("YES\n");

	return 0;
}
