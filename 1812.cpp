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


int     main()
{
	int n;
	scanf("%d", &n);

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	i64 sum = 0;
	for (int i = 0; i < n; i++)
		sum += v[i];
	sum /= 2;

	for (int i = 0; i < n; i++)
	{
		i64 ans = sum;

		for (int j = 1; j < n; j += 2)
		{
			ans -= v[(i + j + n) % n];
		}

		printf("%lld\n", ans);
	}

}