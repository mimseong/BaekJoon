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
#define MOD 1000000009

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

int main() 
{
    int n, m;
    cin >> n >> m;

    vector<int> v(n + 5);
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (v[j] % i > v[j + 1] % i)
                swap(v[j], v[j + 1]);
        }
    }

    for (int i = 1; i <= n; i++)
        cout << v[i] << endl;

    return 0;
}