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

int N, M, A;
vector<int> arr;

bool check(int firstPower) {
    if (arr[0] > firstPower) return false;
    
    int count = 0;
    i64 scoreSum = 0;
    i64 nowPower = firstPower;
    int nowIdx = 0;
    
    while (count < M) {
        bool flag = true;
        for (int i = nowIdx; i < N; i++) {
            if (nowPower < arr[i]) {
                nowIdx = i - 1;
                flag = false;
                break;
            }
        }
        
        if (flag) {
            if (arr[N - 1] <= nowPower) {
                nowIdx = N - 1;
            }
        }
        
        nowPower += arr[nowIdx];
        scoreSum += arr[nowIdx];
        count++;
        if (scoreSum >= A) {
            return true;
        }
    }
    
    return false;
}

i64 binarySearch() {
    int low = 1;
    int high = arr[N - 1];
    i64 ans = MAXV;
    
    if (arr[0] >= A) {
        return A;
    }
    
    while (low <= high) {
        int mid = (low + high) / 2;
        bool ret = check(mid);
        
        if (ret) {
            ans = min(ans, (i64)mid);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return ans;
}

int main() {
    scanf("%d %d %d", &N, &M, &A);
    
    arr.resize(N);
    FOR(i, N) {
        scanf("%d", &arr[i]);
    }
    
    sort(all(arr));
    printf("%lld\n", binarySearch());
    
    return 0;
}