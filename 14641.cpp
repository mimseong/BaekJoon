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

bool visited[50];
vector <int> adj[50];

bool dfs(int curr, int findNode)
{
    visited[curr] = true;
    // printf("%c\n", curr + 'a');
    if (curr == findNode) {
        return true;
    }

    bool result = false;
    for (int next : adj[curr])
    {
        if (!visited[next])
            result |= dfs(next, findNode);
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int m, n;
    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;

        adj[a[0] - 'a'].push_back(b[0] - 'a');
        // cout << a[0] - 'a' << " " << b[0] - 'a' << "\n";
    }

    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;

        if (a.size() != b.size()) {
            cout << "no\n";
            continue;
        }

        bool isMatch = true;
        for (int i = 0; i < a.size(); i++) {
            memset(visited, false, sizeof(visited));
            if (dfs(a[i] - 'a', b[i] - 'a') == false) {
                isMatch = false;
                break;
            }
        }

        cout << (isMatch ? "yes\n" : "no\n");
    }

    // memset(visited, false, sizeof(visited));
    // cout << dfs('i' - 'a', 'z' - 'a') << "\n";

    return 0;
}
