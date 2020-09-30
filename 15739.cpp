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

int v[105][105];

int main() {
    i64 n;
    cin >> n;

    vector<int> count_num(10005);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
            count_num[v[i][j]]++;
        }
    }

    
    for (int i = 1; i <= n*n; i++)
    {
        if (count_num[i] != 1)
        {
            cout << "FALSE" << endl;
            return 0;
        }
    }

    bool check = true;
    vector<i64> sum(4);
    for (int i = 0; i < n; i++)
    {
        sum[3] += v[n - i - 1][i];
        sum[2] += v[i][n - i - 1];

        for (int j = 0; j < n; j++)
        {
            sum[0] += v[i][j];
            sum[1] += v[j][i];
        }


        if (n * (n * n + 1) / 2 != sum[0] || n * (n * n + 1) / 2 != sum[1])
            check = false;

        sum[0] = 0;
        sum[1] = 0;
    }

    if (n * (n * n + 1) / 2 != sum[3] || n * (n * n + 1) / 2 != sum[2])
        check = false;

    if (check)
        cout << "TRUE" << endl;
    else
        cout << "FALSE" << endl;

    return 0;
}