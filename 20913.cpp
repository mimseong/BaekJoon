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

string repeatString(int count) {
    string result = "";
    for (int i = 0; i < count; ++i) {
        result += "0";
    }
    return result;
}

int main() {
	int n;
	scanf("%d", &n);

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
	    scanf("%d", &v[i]);
	}

	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
	    nums[i] = 800 + i;
	}

    string zero = "";
	for (int i = 0; i < n; i++) {
	    cout << to_string(nums[i]) + repeatString(v[i]) << " ";
	    zero += "0";
	}

	return 0;
}
