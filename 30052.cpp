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
#include <cassert>
#include <climits>
#include <tuple>

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()
#define MAXV 987654321
#define FOR(i, n) for (int i = 0; i < (n); ++i)

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

int main() {
    int N, M, D;
    scanf("%d %d", &N, &M);
    scanf("%d", &D);
    
    vector<vector<int>> arr(N + 1, vector<int>(M + 1, 0));
    int ans = 0;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            // 왼쪽 위 모서리 (1,1)에서의 거리 체크
            if(abs(1-i) + abs(1-j) < D) {
                arr[i][j] = 1;
            }
            
            // 왼쪽 아래 모서리 (N,1)에서의 거리 체크
            if(abs(N-i) + abs(1-j) < D && arr[i][j] == 1) {
                arr[i][j] = 2;
            }
            
            // 오른쪽 위 모서리 (1,M)에서의 거리 체크
            if(abs(1-i) + abs(M-j) < D && arr[i][j] == 2) {
                arr[i][j] = 3;
            }
            
            // 오른쪽 아래 모서리 (N,M)에서의 거리 체크
            if(abs(N-i) + abs(M-j) < D && arr[i][j] == 3) {
                ans++;
            }
        }
    }
    
    printf("%d\n", ans);
    return 0;
}
