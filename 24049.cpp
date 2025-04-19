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

int mapv[1005][1005];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);

        mapv[i][0] = a;
    }

    for (int i = 1; i <= m; i++) {
        int a;
        scanf("%d", &a);

        mapv[0][i] = a;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mapv[i][j-1] == mapv[i-1][j]) mapv[i][j] = 0;
            else mapv[i][j] = 1;
        }
    }

    printf("%d\n", mapv[n][m]);

    return 0;
}
