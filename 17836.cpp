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

int mapv[105][105];
int h[105][105];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int main() {
	int n, m, t;
	scanf("%d %d %d", &n, &m, &t);

	for (int i = 1; i <= n; i++) {
	    for (int j = 1; j <= m; j++) {
	        scanf("%d", &mapv[i][j]);
	    }
	}

	queue<ii> Q;
    Q.emplace(1, 1);
    memset(h, -1, sizeof(h));
    h[1][1] = 0;

    int ans = MAXV;
    int gram_h = MAXV;
    ii gram = {-1, -1};


    while (!Q.empty())
    {
        ii curr = Q.front();
        Q.pop();

        // printf("%d %d\n", curr.xx, curr.yy);

        if (curr.xx == n && curr.yy == m)
        {
            ans = h[curr.xx][curr.yy];
            break;
        }

        if (mapv[curr.xx][curr.yy] == 2) {
            gram = curr;
            gram_h = h[curr.xx][curr.yy];
        }

        for (int i = 0; i < 4; i++)
        {
            ii next;
            next.xx = curr.xx + dx[i];
            next.yy = curr.yy + dy[i];

            if (next.xx <= 0 || n < next.xx)
                continue;
            if (next.yy <= 0 || m < next.yy)
                continue;
            if (mapv[next.xx][next.yy] == 1)
                continue;
            if (h[next.xx][next.yy] != -1)
                continue;

            h[next.xx][next.yy] = h[curr.xx][curr.yy] + 1;
            Q.emplace(next.xx, next.yy);
        }
    }


	int gram_len = gram_h + (n - gram.xx + m - gram.yy);

// 	cout << gram_len << endl;
// 	cout << ans << endl;
	int small = min(gram_len, ans);

	if (t < small) {
	    printf("Fail\n");
	} else {
	    printf("%d\n", small);
	}


	return 0;
}
