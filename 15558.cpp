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

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

int n, k;
vector<string> str(2);
bool visited[100005][3];

int main() {
    scanf("%d %d", &n, &k);
    cin >> str[0] >> str[1];

    queue<iii> Q;
    Q.emplace(0, 0, 0);

    int dp[] = { 1, -1, k};
    int ds[] = { 0, 0, 1};
    while (!Q.empty())
    {
        auto [t, p, s] = Q.front();
        Q.pop();

        if (n <= p) {
            printf("1\n");
            return 0;
        }

        // 이동
        int nt = t + 1;
        for(int i = 0; i < 3; i++) {
            int np = p + dp[i];
            int ns = (s + ds[i]) % 2;

            if (np < nt) continue;
            if (np >= n) Q.emplace(nt, np, ns);
            else if (!visited[np][ns] && str[ns][np] == '1') {
                visited[np][ns] = true;
                Q.emplace(nt, np, ns);
            }
        }
    }

    printf("0\n");
    return 0;
}
