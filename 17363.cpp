#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()
#pragma warning(disable:4996)

using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    map<int, int> mp;

    mp[46] = 46;
    mp[79] = 79;
    mp[45] = 124;
    mp[124] = 45;
    mp[47] = 92;
    mp[92] = 47;
    mp[94] = 60;
    mp[60] = 118;
    mp[118] = 62;
    mp[62] = 94;

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c", mp[v[j][i]]);
        }
        printf("\n");
    }

    return 0;
}