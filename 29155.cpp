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
#include <tuple>

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()
#define MAXV 987654321
#define FOR(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

int main() {
	int n;
	scanf("%d", &n);

	vector<int> pv(6);
	for (int i = 1; i<= 5; i++) {
	    scanf("%d", &pv[i]);
	}

	vector<int> v[6];
	for (int i = 0; i < n; i++) {
	    int p, time;
	    scanf("%d %d", &p, &time);

	    v[p].push_back(time);
	}

	for (int i = 1; i<= 5; i++) {
	    sort(all(v[i]));
	}

// 	for (int i = 1; i<= 5; i++) {
// 	    for (int j = 0; j < v[i].size(); j++)
// 	        printf("%d ", v[i][j]);
// 	    printf("\n");
// 	}

	int ans = 0;
	for (int i = 1; i<= 5; i++) {
	    for (int j = 0; j < pv[i]; j++) {
	       // printf("%d ", v[i][j]);
	        ans += v[i][j];
	        if (j > 0) {
	            ans += (v[i][j] - v[i][j-1]);
	           // printf("%d ", v[i][j] - v[i][j-1]);
	        }
	    }
	    if (i < 5 && pv[i+1] != 0) ans += 60;
	   // printf("\n%d\n", ans);
	}
	printf("%d\n", ans);

	return 0;
}
