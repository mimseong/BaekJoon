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

i64 cache[10][65];

i64 func(int start, int N)
{
	if (N == 0) return 1;

	i64& ret = cache[start][N];
	if (ret != 0) return ret;

	for (int i = start; i < 10; i++)
		ret += func(i, N - 1);

	return ret;
}

int     main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);
		printf("%lld\n", func(0, n));
	}
	
}