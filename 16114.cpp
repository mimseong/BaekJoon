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

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

int main() {
    int x, n;
    scanf("%d %d", &x, &n);
    
    if (x < 0 && n == 1) {
        printf("INFINITE\n");
        return 0;
    }
    
    if (x >= 0 && n == 1) {
        printf("0\n");
        return 0;
    }
    
    if (n % 2 == 1) {
        printf("ERROR\n");
        return 0;
    }
    
    if (x <= 0) {
        printf("0\n");
        return 0;
    }
    
    if (n == 0) {
        printf("INFINITE\n");
        return 0;
    }
    
    
    n = n / 2;
    printf("%d\n", (x + n - 1) / n - 1);
    
    
    return 0;
}