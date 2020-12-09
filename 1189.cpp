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

int ans = 0;
int n, m, k;

int xv[] = { 1, 0, -1, 0 };
int yv[] = { 0, 1, 0, -1 };

bool visited[30][30];
char mapv[30][30];

void	func(int x, int y, int cnt)
{
	//printf("%d %d %d\n", x, y, cnt);
	if (x == 0 && y == m - 1)
	{
		//printf("!\n");
		if (cnt == k)
			ans++;
		return;
	}

	
	visited[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + xv[i];
		int ny = y + yv[i];

		if (nx < 0 || n <= nx || ny < 0 || m <= ny)
			continue;

		if (mapv[nx][ny] == 'T' || visited[nx][ny])
			continue;

		func(nx, ny, cnt + 1);
	}

	visited[x][y] = false;
}

int     main()
{
	scanf("%d %d %d", &n, &m, &k);

	char tmp;
	scanf("%c", &tmp);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf("%c", &mapv[i][j]);
		scanf("%c", &tmp);
	}

	func(n - 1, 0, 1);
	printf("%d\n", ans);

	return 0;
}