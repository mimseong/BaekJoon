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
    
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        scanf("%d", &a);
        
        if (a == 0) {
            if (pq.empty())
                printf("-1\n");
            else {
                printf("%d\n", pq.top());
                pq.pop();   
            }
            continue;
        }
        
        for (int i = 0; i < a; i++) {
            int tt;
            scanf("%d", &tt);
            pq.push(tt);
        }
        
        
    }
    
    
    return 0;
}