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

i64 cache[2][100];

i64 func(int start, int N)
{
	if (N == 0) return 1;

	i64& ret = cache[start][N];
	if (ret != 0) return ret;

	i64 sum = 0;
	if (start != 1)
		sum += func(1, N - 1);
	sum += func(0, N - 1);

	return ret = sum;
}

int main()
{
	int N;
	cin >> N;

	cout << func(1, N-1) << endl;


	return 0;
}