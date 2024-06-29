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
	string s;
	cin >> s;

	vector<bool> remove(s.size());

	int num_1 = 0;
	int num_0 = 0;
	for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1')
            num_1++;
        else
            num_0++;
	}

	num_1 /= 2;
	num_0 /= 2;
	for (int i = 0; i < s.size(); i++) {
	    if (s[i] == '1' && 0 < num_1) {
	        remove[i] = true;
	        num_1--;
	    }
	}


	for (int i = s.size() - 1; i >= 0; i--) {
	    if (s[i] == '0' && 0 < num_0) {
	        remove[i] = true;
	        num_0--;
	    }
	}

	for (int i = 0; i < s.size(); i++) {
        if (remove[i])
            continue;
	    printf("%c", s[i]);
	}

	return 0;
}
