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
#define MOD 1000000007

using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

bool sortbyfirst(const pair<int, int>& a, const pair<int, int>& b)
{
    return (a.first < b.first);
}

int     main()
{
    vector<ii> v(8);
    for (int i = 0; i < 8; i++)
    {
        scanf("%d", &v[i].xx);
        v[i].yy = i;
    }
    
    sort(v.begin(), v.end(), sortbyfirst);

    set<int> s;
    int sum = 0;
    for (int i = 7; i >= 3; i--)
    {
        sum += v[i].xx;
        s.insert(v[i].yy + 1);
    }

    printf("%d\n", sum);
    for (auto& si : s)
        cout << si << " ";


    return 0;
}