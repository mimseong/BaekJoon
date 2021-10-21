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

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

int main() {
    int n;
    scanf("%d", &n);
    
    vector<int> in(n);
    vector<int> v1(n);
    vector<int> v2(n);
    
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    
    // 시작점을 미리 구해둔다
    int v1Start = -1;
    int v2Start = -1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &v1[i]);
        v2[n - 1 - i] = v1[i];
        
        if (v1[i] == in[0]) {
            v1Start = i;
        }
        
        if (v2[n - 1 - i] == in[0]) {
            v2Start = n - 1 - i;
        }
    }
    
    // 시작지점 조차 같지 않다면
    if (v1Start == -1) {
        printf("bad puzzle\n");
        return 0;
    }
    
    // 시작지점을 기준으로 -> , <- 방향으로 확인한다 O(n)
    // 둘 중 하나라도 true면 GOOD~
    bool check1 = true;
    for (int i = 0; i < n; i++) {
        if (v1[(v1Start + i) % n] != in[i])
            check1 = false;
    }
    
    bool check2 = true;
    for (int i = n - 1; i >= 0; i--) {
        if (v2[(v2Start + i) % n] != in[i])
            check2 = false;
    }
    
    if (check1 || check2) {
        printf("good puzzle\n");
        return 0;
    }
    
    printf("bad puzzle\n");
    return 0;
}