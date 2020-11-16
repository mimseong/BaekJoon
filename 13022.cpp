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
using iii = tuple<int, int, int>;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int     main()
{
    string s;
    cin >> s;

    int state = 0;
    int w_cnt = 1;
    int cnt = 1;
    bool ans = true;
    for (int i = 0; i < s.size(); i++)
    {
        if (state == 0)
        {
            if (s[i] == 'w')
                state = 1;
            else
                ans = false;
        }
        else if (state == 1)
        {
            if (s[i] == 'o')
            {
                state = 2;
                cnt = 1;
            }
            else if (s[i] == 'w')
                w_cnt++;
            else
                ans = false;
        }
        else if (state == 2)
        {
            if (s[i] == 'l')
            {
                state = 3;
                if (cnt != w_cnt)
                    ans = false;
                cnt = 1;
            }
            else if (s[i] == 'o')
                cnt++;
            else
                ans = false;
        }
        else if (state == 3)
        {
            if (s[i] == 'f')
            {
                state = 4;
                if (cnt != w_cnt)
                    ans = false;
                cnt = 1;
            }
            else if (s[i] == 'l')
                cnt++;
            else
                ans = false;
        }
        else
        {
            if (s[i] == 'w')
            {
                state = 1;
                if (cnt != w_cnt)
                    ans = false;
                w_cnt = 1;
            }
            else if (s[i] == 'f')
                cnt++;
            else
                ans = false;
        }
    }

    if (state != 4)
        ans = false;

    if (cnt != w_cnt)
        ans = false;

    if (ans)
        printf("1\n");
    else
        printf("0\n");
    return 0;
}