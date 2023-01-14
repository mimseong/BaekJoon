#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <bitset>
#include <stdio.h>
#include <math.h>
#include <sstream>
#include<cassert>
#include <climits>

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()
#define MAXV 1000000007

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

int arr[5000005];

int main() {
	int n, m, k;
    scanf("%d %d %d", &n, &k, &m);
	
	m--;
	int start = 0;
	int ret;
	int cnt = n;
	for (int i = 1; i <= cnt; i++) {
		int remove = (start + k - 1) % n;
		if (remove == m) {
			ret = i;
			break;
		}
		m -= remove < m; 
		n--;
		start = remove;
	}
	printf("%d\n", ret);
	return 0;
}