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

int     main()
{
    string s;
    cin >> s;

    int n;
    scanf("%d", &n);
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for(int i = 0; i < 26; i++)
    {
        string tmp = "";
        for (int j = 0; j < s.size(); j++)
        {
            tmp += (s[j] - 'a' + i) % 26 + 'a';
        }

        for (int j = 0; j < v.size(); j++)
        {
            if (tmp.find(v[j]) != string::npos)
            {
                cout << tmp << endl;
                return 0;
            }
        }
    }


    return 0;
}