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

int timetable[105][50005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;

	map<string, bool> name_map;
	map<string, int> place_idx;
	map<int, string> place_name;

	for (int i = 1; i <= n; i++) {
	    string name, place;
	    int from, to;

	    cin >> name >> place >> from >> to;
	    // 첫 번째 제출 말고는 무시함
	    if (name_map[name])
	        continue;
	    name_map[name] = true;

	    // 장소 - 인덱스 매핑
	    if (place_idx[place] == 0) {
	        place_idx[place] = i;
	        place_name[i] = place;
	    }

	    // 몇 번 나왔는지 체크
	    for (int j = from; j < to; j++) {
	        timetable[place_idx[place]][j]++;
	    }

	   // cout << "장소 인덱스" << place_idx[place] << "\n";
	}

// 	FOR(i, 10) {
// 	    FOR(j, 10) cout << timetable[i][j] << " ";
// 	    cout << "\n";
// 	}

	vector<pair<int, string>> v(n + 5);
	for (int i = 1; i <= n; i++) {

	    // 각 장소별 최다 선택 수 구함
	    int maxv = 0;
	    for (int j = 1; j <= 50000; j++) {
	        maxv = max(timetable[i][j], maxv);
	    }

	   // cout << "최다 선택 장소" << place_name[i] << " " << maxv << "\n";
	    v[i].xx = maxv;
	    v[i].yy = place_name[i];
	}

	sort(all(v), greater<pair<int, string>>());
// 	FOR(i, v.size()) cout << v[i].xx << " " << v[i].yy << "\n";

	// 가장 많이 선택된 것 중에서 사전순 1빠 구함
	string max_name;
    int max_number = 0;
	for (int i = 0; i <= n; i++) {
	    if (v[0].xx != v[i].xx)
	        break;
	    max_name = v[i].yy;
	    max_number = v[i].xx;
	}

// 	cout << max_name << "\n";
// 	cout << max_number << "\n";

	bool is_find = false;
	int ans_from = 0;
	int ans_to = 0;
	for (int i = 1; i <= 50000; i++) {
	    if (is_find) break;


	    if (ans_from == 0 && timetable[place_idx[max_name]][i] == max_number) {
	        ans_from = i;
	    }
	    if (timetable[place_idx[max_name]][i] == max_number) {
	        ans_to = i;
	    }

	    if (timetable[place_idx[max_name]][i] != max_number && ans_to != 0) {
	        is_find = true;
	    }
	}

	cout << max_name << " " << ans_from << " " << ans_to + 1 << "\n";

	return 0;
}
