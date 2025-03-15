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

	priority_queue<ii, vector<ii>, greater<ii>> start;
	priority_queue<ii, vector<ii>, greater<ii>> end;
	FOR(i, n) {
	    ii date1, date2;
	    scanf("%d-%d %d-%d", &date1.xx, &date1.yy, &date2.xx, &date2.yy);

	    start.push(date1);
	    end.push(date2);
	   // printf("%d-%d %d-%d\n", date1.xx, date1.yy, date2.xx, date2.yy);
	}

	priority_queue<ii, vector<ii>, greater<ii>> check;
	int max_size = 0;
	ii max_date = start.top();
	while(start.size() > 0) {
	    ii now = start.top();
	    start.pop();
	   // printf("%d-%d\n", now.xx, now.yy);

	    while(!end.empty() && end.top() < now) {
	        end.pop();
	        check.pop();
	    }

	    check.push(now);
	    if(max_size < (int)check.size()) {
	        max_date = now;
	        max_size = check.size();
	    }
	}

    // printf("%d\n", max_size);
    printf("%d-%02d\n", max_date.xx, max_date.yy);

	return 0;
}
