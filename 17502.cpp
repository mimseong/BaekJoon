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
    int n;
    string s;
    cin >> n >> s;

    if (n % 2 == 1 && s[n / 2] == '?')
        s[n / 2] = 'a';

    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] == '?' && s[n - i - 1] == '?')
        {
            s[i] = 'a';
            s[n - i - 1] = 'a';
        }
        else if (s[i] == '?')
            s[i] = s[n - i - 1];
        else if (s[n - i - 1] == '?')
            s[n - i - 1] = s[i];
    }
    
    cout << s;

    return 0;
}