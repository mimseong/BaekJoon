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
#include <cmath>
#include <cstring>

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()

using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int     main()
{
    int k, l;
    cin >> k >> l;
    
    vector<int> size(k + 5);
    for (int i = 1; i <= k; i++)
    {
        string a;
        cin >> a;

        if (a == "S")
            size[i] = 0;
        else if (a == "M")
            size[i] = 1;
        else
            size[i] = 2;
    }

    vector<bool> pick(k + 5);
    for (int i = 0; i < l; i++)
    {
        string a;
        int b, c;
        cin >> a >> b;

        if (a == "S")
            c = 0;
        else if (a == "M")
            c = 1;
        else
            c = 2;

        if (!pick[b] && c <= size[b])
            pick[b] = true;
    }

    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        if (pick[i])
            ans++;
    }

    cout << ans << endl;

    return 0;
}