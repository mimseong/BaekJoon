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

int     main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> size(n + 5);
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;

        if (s == "M")
            size[i] = 1;
        else if (s == "S")
            size[i] = 0;
        else if (s == "L")
            size[i] = 2;
    }

    vector<bool> v(n + 5);
    for (int i = 0; i < m; i++)
    {
        string s;
        int x;

        cin >> s >> x;
        int size_t;
        if (s == "M")
            size_t = 1;
        else if (s == "S")
            size_t = 0;
        else if (s == "L")
            size_t = 2;

        //cout << size_t << " " << size[x] << " " << v[x] << "\n";

        if (!v[x] && size_t <= size[x])
            v[x] = true;
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (v[i])
            cnt++;
    }
    cout << cnt << "\n";

    return 0;
}