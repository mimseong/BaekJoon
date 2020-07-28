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
#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()
#pragma warning(disable:4996)

using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int len(int x1, int x2, int y1, int y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
    int n;
    scanf("%d", &n);

    vector<ii> v(n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &v[i].xx, &v[i].yy);

    int min = 999999999;
    int mini = 0;

    for (int i = 0; i < n; i++)
    {
        int max = -1;
        int maxi = i;
        for (int j = 0; j < n; j++)
        {
            if (j == i)
                continue;

            if (max < len(v[i].xx, v[j].xx, v[i].yy, v[j].yy))
            {
                max = len(v[i].xx, v[j].xx, v[i].yy, v[j].yy);
                maxi = i;
            }
        }

        if (min > max)
        {
            min = max;
            mini = maxi;
        }
    }

    cout << v[mini].xx << " " << v[mini].yy << endl;

    return 0;
}