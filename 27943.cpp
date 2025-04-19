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
    i64 n;
    cin >> n;

    i64 mid = (1 + n + 1) / 2;

    cout << "? " << mid << endl;
    string gaji;
    cin >> gaji;

    // 가지 시작점 파악
    i64 l = 1;
    i64 r = mid;

    while (l != r) {
        i64 mid = (l + r) / 2;

        cout << "? " << mid << endl;
        string s;
        cin >> s;

        if (s == gaji) r = mid;
        else l = mid + 1;
    }

    i64 start = r;

    // 가지 끝점 파악
    l = mid;
    r = n;

    while (l != r) {
        i64 mid = (l + r + 1) / 2;

        cout << "? " << mid << endl;
        string s;
        cin >> s;

        if (s == gaji) l = mid;
        else r = mid - 1;
    }

    i64 end = l;

    // 결과 출력
    cout << "! " << start << " " << end << endl;
}
