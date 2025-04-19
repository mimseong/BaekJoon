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

vector<int> knowledge[15];

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	// 지식 까먹는 시간
	// 1번, .. , N번
	vector<int> vd(N+1);
	FOR (i, N) scanf("%d", &vd[i+1]);

	// 문제를 풀기 위해 필요한 지식
	FOR (i, M) {
	    int K;
	    scanf("%d", &K);

	    FOR (j, K) {
	        int x;
	        scanf("%d", &x);

	        knowledge[i+1].push_back(x);
	    }
	}

	// 문제 순서 정하는 용도
	// 0번 .. M-1번
	vector<int> problems(M);
	FOR (i, M) problems[i] = i;

	int ans = MAXV;
	do {
	    int studyCount = 0;
	    vector<int> mp(1005, -1); // 지식 번호, 마지막으로 언제 공부했는지

        FOR(i, M) {
            // 오늘 풀어야 하는 문제 번호
            int todayProblem = problems[i] + 1;
            FOR(j, knowledge[todayProblem].size()) {
                // 필요한 지식 번호
                int todayKnowledge = knowledge[todayProblem][j];

                // 해당 지식을 공부해야 하는지 확인
                // 공부한 적이 없거나 | 까먹었다면
                int lastStudyDate = mp[todayKnowledge];
                if (lastStudyDate == -1 || lastStudyDate + vd[todayKnowledge] <= i) {
                    // 공부하기
                    studyCount++;
                    mp[todayKnowledge] = i;
                }
            }
        }

        ans = min(studyCount, ans);
	} while (next_permutation(all(problems)));

    printf("%d\n", ans);

	return 0;
}

