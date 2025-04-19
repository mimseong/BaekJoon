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

int colors[500005];

int main() {
    int n;
    scanf("%d", &n);

    int colorNum = 1;
    colors[1] = colorNum++;

    for (int i = 2; i * i <= n; i++)
    {
        if (colors[i] != 0)
            continue;

        colors[i] = colorNum;
        for (int j = (i * 2); j <= n ; j += i) {
            colors[j] = colorNum;
        }
        colorNum++;
    }

    vector<int> ans(n+1);
    for (int i = 1; i <= n; i++)
    {
        if (colors[i] == 0) {
            ans[i] = colorNum++;
        } else {
            ans[i] = colors[i];
        }
    }

    printf("%d\n", colorNum-1);
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}
