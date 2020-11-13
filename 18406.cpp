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

int     main()
{
    string str;
    cin >> str;

    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < str.size() / 2; i++)
        sum1 += str[i] - '0';

    for (int i = str.size() / 2; i < str.size(); i++)
        sum2 += str[i] - '0';

    if (sum1 == sum2)
        printf("LUCKY\n");
    else
        printf("READY\n");

    return 0;
}