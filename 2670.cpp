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

int     main()
{
    int n;
    cin >> n;

    vector<double> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int r = 1;
    double maxv = v[0];
    
    for (int i = 0; i < n; i++)
    {
        double mul = 1;
        for (int j = i; j < n; j++)
        {
            mul *= v[j];
            if (maxv < mul)
                maxv = mul;
        }
    }
    
    printf("%.3lf", maxv);

    return 0;
}