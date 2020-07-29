#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <tuple>
#include <string.h>
#include <math.h>
#include <random>
#include <functional>
#include <assert.h>
#include <math.h>
#define all(x) (x).begin(), (x).end()
#define xx first
#define yy second

using namespace std;

template<typename T, typename Pr = less<T>>
using pq = priority_queue<T, vector<T>, Pr>;
using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int main()
{
	int n;
	scanf("%d", &n);
	
	vector<ii> v(n);
	for (int i = 0; i < n; i++)
	    scanf("%d %d", &v[i].yy, &v[i].xx);
	    
	sort(all(v));
	
	for (int i = 0; i < n; i++)
	    printf("%d %d\n", v[i].yy, v[i].xx);

	return 0;
}