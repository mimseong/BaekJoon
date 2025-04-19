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

	vector<int> v1(n);
	vector<int> v2(n);
	FOR(i, n) {
	    scanf("%d", &v1[i]);
	    v2[i] = v1[i];
	}

	sort(all(v1));

	int incorrectCount = 0;
	FOR (i, v1.size()) {
	    if (v1[i] != v2[i]) incorrectCount++;
	}

	int m;
	scanf("%d", &m);

	FOR (j, m) {
	    int xi, yi;
	    scanf("%d %d", &xi, &yi);

	    swap(v2[xi], v2[yi]);

	    if (n == 2) {
	        if (v2[0] > v2[1]) {
	            printf("1 ");
	            continue;
	        }
	    }

	    if (v1[xi] != v2[yi] && v1[xi] == v2[xi]) incorrectCount--;
	    if (v1[xi] == v2[yi] && v1[xi] != v2[xi]) incorrectCount++;
	    if (v1[yi] != v2[xi] && v1[yi] == v2[yi]) incorrectCount--;
	    if (v1[yi] == v2[xi] && v1[yi] != v2[yi]) incorrectCount++;

	    if (incorrectCount <= 0) printf("0 ");
	    else  printf("-1 ");
	}

	return 0;
}
