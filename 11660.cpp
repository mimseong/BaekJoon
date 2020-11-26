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

i64 mapv[1030][1030];

int     main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%lld", &mapv[i][j]);

	for (int i = 1; i <= n; i++)
		for (int j = 2; j <= n; j++)
			mapv[j][i] += mapv[j-1][i];

	for (int i = 1; i <= n; i++)
		for (int j = 2; j <= n; j++)
			mapv[i][j] += mapv[i][j - 1];

	for (int i = 0; i < m; i++)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		i64 sum = 0;
		sum += mapv[x2][y2];
		sum -= mapv[x1 - 1][y2];
		sum -= mapv[x2][y1 - 1];
		sum += mapv[x1 - 1][y1 - 1];


		printf("%lld\n", sum);
	}
	


	return 0;
}