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

using namespace std;

int n;
string s, backup;
string orignal;

void    switch_on(int i)
{
    if (i != 0)
        s[i - 1] = s[i - 1] == '0' ? '1' : '0';
    s[i] = s[i] == '0' ? '1' : '0';
    if (i != n - 1)
        s[i + 1] = s[i + 1] == '0' ? '1' : '0';
}

int    greedy(int init)
{
    int cnt = init;

    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] != orignal[i - 1])
        {
            switch_on(i);
            cnt++;
        }
    }

    return cnt;
}

int     main()
{
    scanf("%d", &n);

    cin >> s >> orignal;
    backup = s;

    int res1 = greedy(0);
    if (s != orignal)
        res1 = -1;
    
    // 0을 누른 경우
    s = backup;
    switch_on(0);
    int res2 = greedy(1);
    if (s != orignal)
        res2 = -1;

    if (res1 == -1)
        printf("%d\n", res2);
    else if (res2 == -1)
        printf("%d\n", res1);
    else
        printf("%d\n", min(res1, res2));

    return 0;
}