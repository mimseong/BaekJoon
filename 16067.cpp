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

int p[1000005];

bool sortbyfirst(const pair<int,int> &a, const pair<int,int> &b) 
{ 
    return (a.first < b.first); 
}

int main() {
    int num1 = 1;
    int num2 = 2;
    
    memset(p, -1, sizeof(p));
    while (num1 + num2 <= 1000000) {
        p[num1] = num2;
        int tmp = num1;
        num1 = num2;
        num2 += tmp;
    }
    
    int n;
    scanf("%d", &n);
    
    vector<ii> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i].xx);
        v[i].yy = i;
        
        if (p[v[i].xx] == -1)
            v[i].xx = 0;
    }
    
    sort(all(v), sortbyfirst);
    
    for (int i = 0; i < n - 1; i++) {
        if (v[i].xx == 1 && v[i + 1].xx == 1) {
            printf("%d %d\n", v[i].yy + 1, v[i + 1].yy + 1);
            return 0;
        }
        
        if (p[v[i].xx] == v[i + 1].xx) {
            printf("%d %d\n", v[i].yy + 1, v[i + 1].yy + 1);
            return 0;
        }
    }
    
    
    printf("impossible\n");
    
    return 0;
}