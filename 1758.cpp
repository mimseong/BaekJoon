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

	sort(all(v), greater<int>());

	i64 sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i] - i > 0)
			sum += v[i] - i;
	}

	printf("%lld\n", sum);

	return 0;
}