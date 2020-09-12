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


bool comp(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.xx == a.yy)
    {
        if (b.xx == b.yy && a.xx < b.xx)
            return true;
        return false;
    }
    else
    {
        if (b.xx == b.yy)
            return true;
        if ((a.xx + a.yy) % 10 < (b.xx + b.yy) % 10)
            return true;
        return false;
    }
}

int     main()
{
    ii n;
    scanf("%d %d", &n.xx, &n.yy);

    vector<int> card;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            card.emplace_back(j);
        }
    }

    card.erase(find(card.begin(), card.end(), n.xx));
    card.erase(find(card.begin(), card.end(), n.yy));


    vector<ii> v;
    for (int i = 0; i < card.size(); i++)
    {
        for (int j = i + 1; j < card.size(); j++)
        {
            v.emplace_back(card[i], card[j]);
        }
    }

    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (comp(v[i], n))
            ans++;
    }

    printf("%.3lf\n", (double)ans / v.size());

    return 0;
}