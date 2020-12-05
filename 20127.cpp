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

	int idx1 = 0;
	bool check = true;
	bool false1 = false;
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i - 1] > v[i] && check)
		{
			check = false;
			idx1 = i;
		}
		else if (v[i - 1] > v[i] && !check)
		{
			false1 = true;
			break;
		}
	}

	if (v[n-1] > v[0] && !check)
		false1 = true;

	int idx2 = 0;
	bool false2 = false;
	check = true;
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i - 1] < v[i] && check)
		{
			check = false;
			idx2 = i;
		}
		else if (v[i - 1] < v[i] && !check)
		{
			false2 = true;
			break;
		}
	}

	if (v[n - 1] < v[0] && !check)
		false2 = true;

	if (false1 && false2)
		printf("-1\n");
	else if (false1)
		printf("%d\n", idx2);
	else if (false2)
		printf("%d\n", idx1);
	else
		printf("%d\n", min(idx1, idx2));

	return 0;
}