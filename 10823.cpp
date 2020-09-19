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

int     main()
{
    string in, str = "";
   
    while (cin >> in)
        str += in;

    string tmp = "";
    int sum = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ',')
        {
            sum += stoi(tmp);
            tmp = "";
            continue;
        }

        tmp += str[i];
    }

    sum += stoi(tmp);
    cout << sum;

    return 0;
}