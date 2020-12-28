#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <deque>
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

int     main()
{
    int n;
    scanf("%d", &n);

    deque<int> dq;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        if (s == "push_back")
        {
            int a;
            cin >> a;

            dq.push_back(a);
        }
        else if (s == "push_front")
        {
            int a;
            cin >> a;

            dq.push_front(a);
        }
        else if (s == "front")
        {
            if (!dq.empty())
                cout << dq.front() << endl;
            else
                cout << "-1" << endl;
        }
        else if (s == "back")
        {
            if (!dq.empty())
                cout << dq.back() << endl;
            else
                cout << "-1" << endl;
        }
        else if (s == "size")
        {
            cout << dq.size() << endl;
        }
        else if (s == "empty")
        {
            cout << dq.empty() << endl;
        }
        else if (s == "pop_front")
        {
            if (dq.empty())
                cout << "-1" << endl;
            else
            {
                cout << dq.front() << endl;
                dq.pop_front();
            }
        }
        else if (s == "pop_back")
        {
            if (dq.empty())
                cout << "-1" << endl;
            else
            {
                cout << dq.back() << endl;
                dq.pop_back();
            }
        }
    }


    return 0;
}