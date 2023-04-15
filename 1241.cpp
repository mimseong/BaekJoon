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

int main() {
    int n;
    scanf("%d", &n);

    vector<int> v(n);
    int maxV = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        maxV = max(v[i], maxV);
    }

    vector<int> count(maxV+1);
    for (int i = 0;  i < n; i++)
        count[v[i]]++;

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j*j <= v[i]; j++) {
            if (v[i] % j != 0)
                continue;

            ans[i] += count[j];
            if (j != v[i] / j)
                ans[i] += count[v[i] / j];
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d\n", ans[i] - 1);

    return 0;
}
