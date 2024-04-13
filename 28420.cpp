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

int mapv[305][305];
int n, m;
int a, b, c;

// 1안
int solve1() {
    int result = MAXV;

    FOR (x, n - a + 1) {
        FOR (y, m - (b+c) + 1) {
            int sum = 0;

            for (int i = x; i < x + a; i++) {
                for (int j = y; j < y + b + c; j++) {
                    sum += mapv[i][j];
                }
            }

            result = min(sum, result);
        }
    }
    return result;
}

// 2안
int solve2() {
    int result = MAXV;

    FOR (x, n - (a+b) + 1) {
        FOR (y, m - (a+c) + 1) {
            int sum = 0;

            for (int i = x; i < x + a; i++) {
                for (int j = y; j < y + c; j++) {
                    sum += mapv[i][j];
                }
            }

            for (int i = x + a; i < x + a + b; i++) {
                for (int j = y + c; j < y + c + a; j++) {
                    sum += mapv[i][j];
                }
            }

            // printf("(%d, %d): %d\n", x, y, sum);

            result = min(sum, result);
        }
    }
    return result;
}

// 3안
int solve3() {
    int result = MAXV;

    FOR (x, n - (a+c) + 1) {
        FOR (y, m - (b+a) + 1) {
            int sum = 0;

            for (int i = x; i < x + a; i++) {
                for (int j = y; j < y + b; j++) {
                    sum += mapv[i][j];
                }
            }

            for (int i = x + a; i < x + a + c; i++) {
                for (int j = y + b; j < y + b + a; j++) {
                    sum += mapv[i][j];
                }
            }

            result = min(sum, result);
        }
    }
    return result;
}

int main() {
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &a, &b, &c);

	FOR (i, n) FOR (j, m) scanf("%d", &mapv[i][j]);

	int ans = MAXV;

	ans = min(solve1(), ans);
	ans = min(solve2(), ans);
	ans = min(solve3(), ans);

	printf("%d\n", ans);

	return 0;
}
