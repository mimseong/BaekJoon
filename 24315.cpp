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
	double a1, a0, c1, c2, n0;
	scanf("%lf %lf\n%lf %lf\n%lf", &a1, &a0, &c1, &c2, &n0);
// 	cout << a1 << a0<< c1<< c2<< n0;

	bool check1 = false;
	if ((c2 > a1) && (a0 / (c2-a1) <= n0)) {
	    check1 = true;
	}
	if ((c2 == a1) && a0 <= 0) check1 = true;
	if ((c2 < a1) && (n0 <= (-1 * a0 / (a1 - c2)))) check1 = true;

	bool check2 = false;
	if ((c1 > a1) && (n0 <= a0 / (c1-a1))) check2 = true;
	if ((c1 == a1) && (0 <= a0)) check2 = true;
	if ((c1 < a1) && (-1 * a0 / (a1 - c1) <= n0)) check2 = true;

	cout << (check1 & check2);


	return 0;
}
