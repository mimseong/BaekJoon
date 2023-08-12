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

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

int main() {
    int n;
    scanf("%d", &n);

    vector<ii> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &v[i].xx, &v[i].yy);
    }

    sort(all(v), [](const ii& a, const ii& b) {
		if (a.yy == b.yy) return a.xx > b.xx;
		return a.yy < b.yy;
	});

	stack<int> r1, r2;
	r1.push(-1);
	r2.push(-1);

	for (int i = 0; i < v.size(); i++) {
	    // 둘 다 가능할 때
	    if (r1.top() <= v[i].xx && r2.top() <= v[i].xx) {
	        if (r1.top() < r2.top()) r2.push(v[i].yy);
	        else r1.push(v[i].yy);
	    }
	    else if (r1.top() <= v[i].xx) r1.push(v[i].yy);
	    else if (r2.top() <= v[i].xx) r2.push(v[i].yy);
	}

	printf("%d\n", r1.size() + r2.size() -2);

    return 0;
}
