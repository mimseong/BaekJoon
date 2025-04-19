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

int mapv[25][15];
int sumv[25][15];
int N, M, A, B;
int ANS = MAXV;

void combination2(vector<int> &v, int n, int r, vector<int> &rows) {
    vector<bool> check(n - r, false);
	check.insert(check.end(), r, true);

	do {
	    vector<int> cols;
		for (int i = 0; i < n; i++) {
			if (!check[i])
			    continue;

			cols.push_back(v[i]);
		}
		cols.push_back(M);

        int ans = 0;
		for (int i = 0; i < rows.size(); i++) {
		    if (ans > ANS) break;
		    for (int j = 0; j < cols.size(); j++) {
		        if (ans > ANS) break;

		        int sum = sumv[rows[i]][cols[j]];
		        if (i > 0) sum -= sumv[rows[i-1]][cols[j]];
		        if (j > 0) sum -= sumv[rows[i]][cols[j-1]];
		        if (i > 0 && j > 0) sum += sumv[rows[i-1]][cols[j-1]];

		        ans = max(ans, sum);
		    }
		}

		ANS = min(ans, ANS);
	} while (next_permutation(check.begin(), check.end()));
}


void combination(vector<int> &v, int n, int r, vector<int> &col) {
    vector<bool> check(n - r, false);
	check.insert(check.end(), r, true);

	do {
	    vector<int> rows;
		for (int i = 0; i < n; i++) {
			if (!check[i])
			    continue;

			rows.push_back(v[i]);
		}
		rows.push_back(N);
		combination2(col, col.size(), B, rows);

	} while (next_permutation(check.begin(), check.end()));
}

void solve() {
    // 나눌 수 있는 행과 열
	vector<int> row(N-1);
	vector<int> col(M-1);

	for (int i = 0; i < row.size(); i++) {
        row[i] = i + 1;
	}
	for (int i = 0; i < col.size(); i++) {
        col[i] = i + 1;
	}

    combination(row, row.size(), A, col);
}

int main() {
	scanf("%d %d", &N, &M);
	scanf("%d %d", &A, &B);

	for (int i = 1; i <= N; i++) {
	    for (int j = 1; j <= M; j++) {
	        scanf("%d", &mapv[i][j]);
	    }
	}

	for (int i = 1; i <= N + 1; i++) {
	    for (int j = 1; j <= M + 1; j++) {
	        sumv[i][j] = sumv[i-1][j] + sumv[i][j-1] + mapv[i][j] - sumv[i-1][j-1];
	    }
	}

    solve();

    printf("%d\n", ANS);

	return 0;
}
