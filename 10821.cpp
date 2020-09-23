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

int     main()
{
    string str;
    cin >> str;

    int ans = 1;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ',')
            ans++;
    }

    cout << ans << endl;

    return 0;
}