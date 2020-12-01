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
	{
		scanf("%d", &v[i]);
	}

	sort(all(v));

	for (int i = 0; i < n; i++)
	{
		printf("%d\n", v[i]);
	}


	return 0;
}