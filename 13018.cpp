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

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    
    if (n == k) {
        printf("Impossible\n");
    } else if (n == k + 1) {
        for (int i = 1; i <= n; i++) {
            printf("%d ", i);
        }
    } else {
        printf("%d ", k + 2);
        for (int i = 2; i <= k + 1; i++) {
            printf("%d ", i);
        }
        for (int i = k + 2; i <= n; i++) {
            printf("%d ", (i < n ? i + 1 : 1));
        }
    }
    
    return 0;
}