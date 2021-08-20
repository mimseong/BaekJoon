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

void	find_heart(vector<string> &v, int n, int &hx, int &hy)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[i][j] == '*')
			{
				hx = i + 1;
				hy = j;
				return;
			}
		}
	}
}

int     main()
{
	int n;
	scanf("%d", &n);

	vector<string> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int hx = 0, hy = 0;
	find_heart(v, n, hx, hy);
	printf("%d %d\n", hx + 1, hy + 1);

	int len = 0;
	for (int i = 1; 0 <= hy - i ; i++)
	{
		if (v[hx][hy - i] != '*')
			break;
		len++;
	}
	printf("%d ", len);

	len = 0;
	for (int i = 1; hy + i < n; i++)
	{
		if (v[hx][hy + i] != '*')
			break;
		len++;
	}
	printf("%d ", len);

	len = 0;
	int ex, ey;
	for (int i = 1; hx + i < n; i++)
	{
		if (v[hx + i][hy] != '*')
		{
			ex = hx + i - 1;
			ey = hy;
			break;
		}
		len++;
	}
	printf("%d ", len);

	len = 0;
	for (int i = 1; ex + i < n; i++)
	{
		if (v[ex + i][ey - 1] != '*')
			break;
		len++;
	}
	printf("%d ", len);
	
	len = 0;
	for (int i = 1; ex + i < n ; i++)
	{
		if (v[ex + i][ey + 1] != '*')
			break;
		len++;
	}
	printf("%d ", len);


	return 0;
}