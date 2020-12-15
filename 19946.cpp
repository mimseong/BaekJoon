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
	string s;
	cin >> s;

	if (s.size() > 10)
		s = s.substr(s.size() - 10);

	i64 n = stoll(s);

	vector<i64> ans(65);
	for (int i = 0; i <= 64; i++)
	{
		i64 x = 1;

		if (i == 0)
			x--;

		for (int j = 1; j <= 64; j++)
		{
			x = (x * 2) % 10000000000;
			if (i == j)
				x--;
		}

		ans[i] = x;
	}

	for (int i = 0; i < ans.size(); i++)
	{
		if (n == ans[i])
			printf("%d\n", i);
	}

	return 0;
}