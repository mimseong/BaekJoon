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
#include <bitset>

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()

using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;


int     main()
{
    int n, m;
    while (cin >> n >> m)
    {
        int ans = 0;
        for (int i = n; i <= m; i++)
        {
            string s = to_string(i);

            vector<int> count(10);
            bool check = false;
            for (int j = 0; j < s.size(); j++)
            {
                count[s[j] - '0']++;
                if (count[s[j] - '0'] > 1)
                {
                    check = true;
                    break;
                }
            }
            if (check)
                continue;

            ans++;
        }
        cout << ans << endl;
    }

    return 0;
}