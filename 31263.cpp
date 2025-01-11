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
    cin >> n;

	string s;
	cin >> s;

	int ans = 0;
	FOR (i, s.size()) {
	    int num3 = stoi(s.substr(i, 3));
	    if (num3 <= 641 && !(i + 3 < s.size() && s[i + 3] == '0')) {
	        // 세 자리 잘랐는데 617보다 작고 다음 숫자가 0이 아닌 경우
            i += 2;
	    } else if (!(i + 2 < s.size() && s[i + 2] == '0')) {
	        // 두 자리 잘랐는데 다음 숫자가 0이 아닌 경우
	        i += 1;
	    }
	    // 그게 아니면 한 자리 자르기
	    ans++;
	}

	cout << ans;

	return 0;
}
