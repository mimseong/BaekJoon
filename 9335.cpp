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

int n;
int result;
vector<vector<int>> friendList;
vector<int> visited;

void backTracking(int index, int count) {
    if (count >= result) {
        return;
    }
    
    if (index == n) {
        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0) {
                return;
            }
        }
        result = count;
        return;
    }
    
    visited[index + 1]++;
    for (int friend_idx : friendList[index + 1]) {
        visited[friend_idx]++;
    }
    backTracking(index + 1, count + 1);
    
    visited[index + 1]--;
    for (int friend_idx : friendList[index + 1]) {
        visited[friend_idx]--;
    }
    backTracking(index + 1, count);
}

int main() {
    int test;
    scanf("%d", &test);
    
    for (int i = 1; i <= test; i++) {
        result = INT_MAX;
        scanf("%d", &n);
        
        friendList.clear();
        friendList.resize(n + 1);
        visited.clear();
        visited.resize(n + 1, 0);
        
        for (int j = 1; j <= n; j++) {
            int friendCount;
            scanf("%d", &friendCount);
            
            for (int k = 0; k < friendCount; k++) {
                int friend_num;
                scanf("%d", &friend_num);
                friendList[j].push_back(friend_num);
            }
        }
        
        backTracking(0, 0);
        printf("%d\n", result);
    }
    
    return 0;
}
