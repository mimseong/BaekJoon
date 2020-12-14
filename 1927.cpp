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

	priority_queue<int, vector<int>, greater<int> > pq;

	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);

		if (x != 0)
		{
			pq.push(x);
			continue;
		}

		if (pq.empty())
		{
			printf("0\n");
			continue;
		}

		printf("%d\n", pq.top());
		pq.pop();
	}

	return 0;
}