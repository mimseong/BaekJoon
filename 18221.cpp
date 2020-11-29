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

int v[1005][1005];

double  calc_len(int a, int b, int c, int d)
{
    return sqrt((a-c)*(a-c) + (b-d)*(b-d));
}

int     main()
{
    int n;
    cin >> n;

    ii sung_kyu, professor;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 2)
                sung_kyu.xx = i, sung_kyu.yy = j;
            if (v[i][j] == 5)
                professor.xx = i, professor.yy = j;
        }
    }

    if (calc_len(sung_kyu.xx, sung_kyu.yy, professor.xx, professor.yy) < 5.0)
    {
        printf("0\n");
        return 0;
    }

    if (sung_kyu.xx > professor.xx)
        swap(sung_kyu.xx, professor.xx);

    if (sung_kyu.yy > professor.yy)
        swap(sung_kyu.yy, professor.yy);

    int cnt = 0;
    for (int i = sung_kyu.xx; i <= professor.xx; i++)
    {
        for (int j = sung_kyu.yy; j <= professor.yy; j++)
        {
            if (v[i][j] == 1)
                cnt++;
        }
    }

    if (cnt < 3)
    {
        printf("0\n");
        return 0;
    }

    
    printf("1\n");
    return 0;
}