#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()

using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int main() {
    int t;
    scanf("%d", &t);

    vector<ii> v(41);
    v[0].xx = 1;
    v[1].yy = 1;

    for (int i = 2; i <= 40; i++)
    {
        v[i].xx = v[i - 1].xx + v[i - 2].xx;
        v[i].yy = v[i - 1].yy + v[i - 2].yy;
    }

    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        printf("%d %d\n", v[n].xx, v[n].yy);
    }

    return 0;
}