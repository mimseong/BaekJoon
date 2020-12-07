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

	vector<int> v[5005];
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);

		v[y].push_back(x);
	}

	i64 ans = 0;
	for (int i = 0; i < 5005; i++)
	{
		sort(all(v[i]));

		if (v[i].size() == 1)
			continue;

		for (int j = 0; j < v[i].size(); j++)
		{
			int a = 100009, b = 100009;

			if (j != 0)
				a = v[i][j] - v[i][j - 1];
			if (j != v[i].size() - 1)
				b = v[i][j + 1] - v[i][j];

			ans += min(a, b);
		}
	}

	printf("%lld\n", ans);

	return 0;
}