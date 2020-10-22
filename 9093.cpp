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
    int t;
    cin >> t;
    cin.ignore();

    for (int i = 0; i < t; i++)
    {
        string s;
        getline(cin, s);

        string tmp = "";
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] != ' ')
            {
                tmp += s[j];
                continue;
            }

            reverse(all(tmp));
            cout << tmp << " ";
            tmp = "";
        }

        reverse(all(tmp));
        cout << tmp << " ";
        cout << endl;
    }

    return 0;
}