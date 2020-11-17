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

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()

using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int check[12];

void calc(int i)
{
    if (is_ok(i))
    {
        if (i == 11)
            return;
        for (int j = 0; j < 12; j++)
        {
            check[i + 1] = j;
    }
}

int     main()
{
    vector<int> ans(12, -1);

    int idx = 0;
    for (int i = 0; i < 5; i++)
    {
        string str;
        cin >> str;

        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] != '.')
            {
                if (str[i] != 'x')
                    ans[idx] = str[i] - 'A';
                idx++;
            }
        }
    }

    for (int i = 0; i < 12; i++)
        check[i] = i;

    for (int j = 0; j < ans.size(); j++)
    {
        if (ans[j] != -1)
            check.erase(find(check.begin(), check.end(), ans[j]));
    }

    for (int i = 0; i < check.size(); i++)
        printf("%c\n", check[i] + 'A');



    return 0;
}