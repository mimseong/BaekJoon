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

vector<int> parent;

void    init(int n)
{
    parent.resize(n + 1);

    for (int i = 0; i <= n; i++)
        parent[i] = i;
}

int     find(int x)
{
    if (x == parent[x])
        return x;
    return (parent[x] = find(parent[x]));
}

void    merge(int x, int y)
{
    x = find(x);
    y = find(y);
    
    parent[x] = y;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    init(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        
        merge(u, v);
    }
    
    int ans = 0;
    vector<int> count(n + 1);
    for (int i = 1; i <= n; i++) {
        int parentNum = find(i);
        if (count[parentNum] == 0)
            ans++;
        count[parentNum]++;
    }
    
    printf("%d\n", ans);
    
    return 0;
}