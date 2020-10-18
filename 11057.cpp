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
#define MOD 10007

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

int cache[10][1005];

int func(int start, int N)
{
	if (N == 0) return 1;

	int& ret = cache[start][N];
	if (ret != 0) return ret;

	for (int i = start; i < 10; i++)
		ret += func(i, N - 1) % 10007;

	return ret % 10007;
}

int main()
{
	int N;
	cin >> N;

	cout << func(0, N) << endl;


	return 0;
}