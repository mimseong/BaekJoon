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
    int r, c, v, h;
    scanf("%d %d %d %d", &r, &c, &v, &h);
    
    vector<int> vv(v);
    vector<int> hv(h);
    for (int i = 0; i < v; i++)
        scanf("%d", &vv[i]);
    for (int i = 0; i < h; i++)
        scanf("%d", &hv[i]);
    
    int start;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < vv[i]; j++) {
            start = i % 2;
            for (int k = 0; k < h; k++) {
                for (int h = 0; h < hv[k]; h++) {
                    if (start == 0)
                    printf("B");
                else
                    printf("W");
                }
                start = (start + 1) % 2;
            }
            printf("\n");
        }
    }
    
    
    return 0;
}