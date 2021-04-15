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


bool visited[100005];
queue<ii> q;

bool valid(int n) {
    if (n < 0 || n > 100000 || visited[n])
        return false;
    return true;
}

int bfs(int k) {
    while(!q.empty())
    {
        int data = q.front().xx;
        int depth = q.front().yy;
        q.pop();
        
        if (data == k)
            return depth;
        
        if (valid(data - 1)) {
            q.push({data - 1, depth + 1});
            visited[data - 1] = true;
        }
        if (valid(data + 1)) {
            q.push({data + 1, depth + 1});
            visited[data + 1] = true;
        }
        if (valid(data * 2)) {
            q.push({data * 2, depth + 1});
            visited[data * 2] = true;
        }
    }
    return 0;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    q.push({n, 0});
    visited[n] = true;
    cout << bfs(k);
    
    
    return 0;
}