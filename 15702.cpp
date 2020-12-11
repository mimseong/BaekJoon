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
	int n, m;
	scanf("%d %d", &n, &m);

	vector<int> point(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &point[i]);

	vector<ii> v(m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &v[i].yy);
		v[i].yy *= -1;

		for (int j = 0; j < n; j++)
		{
			string s;
			cin >> s;

			if (s == "X")
				continue;

			v[i].xx += point[j];
		}
	}

	sort(all(v), greater<>());

	printf("%d %d\n", v[0].yy * -1, v[0].xx);

	return 0;
}