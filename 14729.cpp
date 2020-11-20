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

double	find_min(vector<double> &v)
{
	int minidx = 0;
	for (int i = 1; i < v.size(); i++)
		if (v[minidx] > v[i])
			minidx = i;

	double ans = v[minidx];
	v[minidx] = 200;
	return ans;
}

int     main()
{
	int n;
	scanf("%d", &n);

	vector<double> v(n);
	for (int i = 0; i < n; i++)
		scanf("%lf", &v[i]);
	for (int i = 0; i < 7; i++)
		printf("%.3lf\n", find_min(v));
	
	return 0;
}