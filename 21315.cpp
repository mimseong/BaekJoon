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

int n;
vector<int> two = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void mix(vector<int>& cards, int range, int cnt) {
    vector<int> new_cards(n);
    int idx = 0;
    
    // 직전에 위로 올린 카드들 중에서 cnt개를 위로
    for (int i = range - cnt; i < range; i++) {
        new_cards[idx++] = cards[i];
        cards[i] = 0;
    }
    
    // 나머지 카드들
    for (int i = 0; i < n; i++) {
        if (cards[i] != 0) {
            new_cards[idx++] = cards[i];
        }
    }
    
    cards = new_cards;
}

void solve(vector<int>& cards, int k) {
    int range = n;
    for (int i = 1; i <= k + 1; i++) {
        int cnt = pow(2, k - i + 1);
        mix(cards, range, cnt);
        range = cnt;
    }
}

int main() {
    scanf("%d", &n);
    
    vector<int> target(n);
    FOR(i, n) {
        scanf("%d", &target[i]);
    }
    
    for(int k1 = 1; pow(2, k1) <= n; k1++) {
        for(int k2 = 1; pow(2, k2) <= n; k2++) {
            vector<int> cards(n);
            FOR(i, n) {
                cards[i] = i + 1;
            }
            
            solve(cards, k1);
            solve(cards, k2);
            
            bool is_finish = true;
            FOR(i, n) {
                if (target[i] != cards[i]) {
                    is_finish = false;
                    break;
                }
            }
            
            if (is_finish) {
                printf("%d %d\n", k1, k2);
                return 0;
            }
        }
    }
    
    return 0;
}