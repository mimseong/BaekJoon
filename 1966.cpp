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

void solve()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int search;
    priority_queue<int> pq;
    queue<ii> now;
    for (int i = 0; i < n; i++)
    {
        int in;
        scanf("%d", &in);

        if (i == m)
            search = in;
        pq.push(in);
        now.emplace(in, i);
    }

    int ans = 0;
    while (!pq.empty())
    {
        int top_pq = pq.top();
        ii top_q = now.front();
        now.pop();

        if (top_pq != top_q.first)
        {
            now.push(top_q);
            continue;
        }

        if (search == top_q.first && top_q.second == m)
            break;
        
        ans++;
        pq.pop();
    }

    cout << ans + 1 << endl;
}

int     main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
        solve();

    return 0;
}