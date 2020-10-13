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

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()

using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int v[105][105];
int n, m;

void print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
}

void func1()
{
    int tmp[105][105];

    for (int i = n - 1, k = 0; i >= 0; i--, k++)
    {
        for (int j = 0, l = 0; j < m; j++, l++)
            tmp[k][l] = v[i][j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            v[i][j] = tmp[i][j];
    }
}

void func2()
{
    int tmp[105][105];

    for (int i = 0, k = 0; i < n; i++, k++)
    {
        for (int j = m-1, l = 0; j >= 0; j--, l++)
            tmp[k][l] = v[i][j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            v[i][j] = tmp[i][j];
    }
}

void func3()
{
    int tmp[105][105];

    for (int i = 0, k = 0; i < m; i++, k++)
    {
        for (int j = n-1, l = 0; j >= 0; j--, l++)
            tmp[k][l] = v[j][i];
    }

    int t = n;
    n = m;
    m = t;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            v[i][j] = tmp[i][j];
    }
}

void func4()
{
    int tmp[105][105];

    for (int i = m - 1, k = 0; i >= 0; i--, k++)
    {
        for (int j = 0, l = 0; j < n; j++, l++)
            tmp[k][l] = v[j][i];
    }

    int t = n;
    n = m;
    m = t;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            v[i][j] = tmp[i][j];
    }
}

void func5()
{
    int tmp[105][105];
    bool ligth = true;

    for (int i = 0, k = 0, l = 0; i < n / 2; )
    {
        for (int j = 0; j < m / 2; j++, l++)
        {
            if (ligth)
                tmp[k][l] = v[i + n / 2][j];
            else
                tmp[k][l] = v[i][j];
        }
        if (ligth)
            ligth = false;
        else
        {
            ligth = true;
            l = 0;
            k++;
            i++;
        }
    }

    ligth = true;
    for (int i = 0, k = n / 2, l = 0; i < n / 2; )
    {
        for (int j = m / 2; j < m; j++, l++)
        {
            if (ligth)
                tmp[k][l] = v[i + n / 2][j];
            else
                tmp[k][l] = v[i][j];
        }
        if (ligth)
            ligth = false;
        else
        {
            ligth = true;
            l = 0;
            i++;
            k++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            v[i][j] = tmp[i][j];
    }
}

void func6()
{
    int tmp[105][105];
    bool ligth = false;

    for (int i = 0, k = 0, l = 0; i < n / 2; )
    {
        for (int j = m / 2; j < m; j++, l++)
        {
            if (ligth)
                tmp[k][l] = v[i + n / 2][j];
            else
                tmp[k][l] = v[i][j];
        }
        if (!ligth)
            ligth = true;
        else
        {
            ligth = false;
            l = 0;
            k++;
            i++;
        }
    }

    ligth = false;
    for (int i = 0, k = n / 2, l = 0; i < n / 2; )
    {
        for (int j = 0; j < m / 2; j++, l++)
        {
            if (ligth)
                tmp[k][l] = v[i + n / 2][j];
            else
                tmp[k][l] = v[i][j];
        }
        if (!ligth)
            ligth = true;
        else
        {
            ligth = false;
            l = 0;
            i++;
            k++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            v[i][j] = tmp[i][j];
    }
}

int     main()
{
    int r;
    cin >> n >> m >> r;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> v[i][j];
    }

    for (int i = 0; i < r; i++)
    {
        int a;
        cin >> a;

        switch (a)
        {
        case 1:
            func1();
            break;
        case 2:
            func2();
            break;
        case 3:
            func3();
            break;
        case 4:
            func4();
            break;
        case 5:
            func5();
            break;
        case 6:
            func6();
            break;
        }
    }

    print();

    return 0;
}