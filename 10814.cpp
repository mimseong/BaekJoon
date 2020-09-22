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

bool sortbyfirst(const pair<int, string>& a, const pair<int, string>& b)
{
    return (a.first < b.first);
}

int     main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<pair<int, string>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].xx >> v[i].yy;

    stable_sort(all(v), sortbyfirst);
    for (int i = 0; i < n; i++)
        cout << v[i].xx << " " << v[i].yy << '\n';

    return 0;
}
