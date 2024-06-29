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

	if (n == 10) {
	    printf("-1\n");
	    return 0;
	}

	map<ii, bool> mp;
	FOR (i, n) {
	    int u, v;
	    scanf("%d %d", &u, &v);

	    if (u > v)
	        swap(u, v);

	    mp[{u, v}] = true;
	}

	int col = 0;
    // (1,3) - (2,4), (2,5)
    if (mp[{ 1,3 }])
    {
        if (mp[{ 2,4 }])
            col++;

        if (mp[{ 2,5 }])
            col++;
    }

    // (1,4) - (2,5), (3,5)
    if (mp[{ 1,4 }])
    {
        if (mp[{ 2,5 }])
            col++;

        if (mp[{ 3,5 }])
            col++;
    }

    // (2,4) - (3,5)
    if (mp[{ 2,4 }])
    {
        if (mp[{ 3,5 }])
            col++;
    }

	if (col == 5) {
	    printf("2\n");
	} else if (1 <= col) {
	    printf("1\n");
	} else {
	    printf("0\n");
	}



	return 0;
}
