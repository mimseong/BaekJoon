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
#include <cmath>
#include <cstring>
#include <bitset>

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

double n, l, w, h;

bool check(double mid)
{
    if (floor(l / mid) * floor(w / mid) * floor(h / mid) < n)
        return false;
    return true;
}

int main()
{
    cin >> n >> l >> w >> h;

    double lo = 0;
    double hi = 1000000000;

    for (int i = 0; i < 100; i++)
    {
        double mid = (lo + hi) * 0.5;

        if (check(mid))
            lo = mid;
        else
            hi = mid;
    }

    printf("%.10lf\n", lo);


    return 0;
}