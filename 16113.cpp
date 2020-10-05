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
#include <bitset>

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

bool v[5][20005];

int     main()
{
    int n; string str;
    cin >> n >> str;

    n /= 5;
    for (int i = 0, k = 0; i < 5; i++)
    {
        for (int j = 0; j < n; j++, k++)
        {
            if (str[k] == '#')
                v[i][j] = true;
            else
                v[i][j] = false;
        }
    }

    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if (!v[0][i] && !v[1][i] && !v[2][i] && !v[3][i] && !v[4][i])
            continue;

        if (v[0][i])
        {
            if (v[0][i] && v[1][i] && v[2][i] && v[3][i] && v[4][i])
            {
                if (!v[0][i + 1] && !v[1][i + 1] && !v[2][i + 1] && !v[3][i + 1] && !v[4][i + 1])
                {
                    ans += "1";
                    i -= 2;
                }
                else if (v[0][i + 2] && v[1][i + 2] && v[2][i + 2] && v[3][i + 2] && v[4][i + 2])
                {
                    if (v[2][i + 1])
                        ans += "8";
                    else
                        ans += "0";
                }
                else
                    ans += "6";
            }
            else if (v[0][i] && v[1][i] && v[2][i] && !v[3][i] && v[4][i])
            {
                if (v[1][i + 2])
                    ans += "9";
                else
                    ans += "5";
            }
            else if (v[0][i] && !v[1][i] && v[2][i] && v[3][i] && v[4][i])
                ans += "2";
            else if (v[0][i] && !v[1][i] && v[2][i] && !v[3][i] && v[4][i])
                ans += "3";
            else if (v[0][i] && v[1][i] && v[2][i] && !v[3][i] && !v[4][i])
                ans += "4";
            else
                ans += "7";
            i += 2;
        }

    }

    cout << ans << endl;

    return 0;
}