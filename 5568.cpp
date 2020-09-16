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

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()

using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int v[10];
bool visited[10];
vector<int> selects;
set<string> ans;
int n, m;

void	comb(int depth)
{
	if (depth == m)
	{
		string str;

		for (int i = 0; i < m; i++)
			str += to_string(selects[i]);
		
		ans.insert(str);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (visited[i])
			continue;

		visited[i] = true;
		selects.push_back(v[i]);
		comb(depth + 1);
		visited[i] = false;
		selects.pop_back();
	}
}

int     main()
{
    scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	comb(0);

	cout << ans.size();
    
    return 0;
}

