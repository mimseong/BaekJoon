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
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n;
	cin >> n;

	vector<string> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	vector<int> word1(26);
	for (int i = 0; i < v[0].size(); i++)
		word1[v[0][i] - 'A']++;

	int ans = 0;
	for (int i = 1; i < n; i++)
	{
		vector<int> word2(26);
		for (int j = 0; j < v[i].size(); j++)
			word2[v[i][j] - 'A']++;

		int diff = 0;
		for (int j = 0; j < word1.size(); j++)
			diff += abs(word1[j] - word2[j]);
		if (diff < 2 && abs((int)v[0].size() - (int)v[i].size()) <= 1)
		{
			ans++;
			continue;
		}

		diff = 0;
		for (int j = 0; j < word1.size(); j++)
		{
			if (abs(word1[j] - word2[j]) >= 2)
				diff++;
			diff += abs(word1[j] - word2[j]);
		}
		if (diff == 2 && v[0].size() == v[i].size())
			ans++;
	}

	cout << ans << endl;

	return 0;
}