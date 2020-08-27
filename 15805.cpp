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

int stack_[200005];

int     main()
{
    int n;
    scanf("%d", &n);

    int top = 1;
    vector<int> v(n);
    vector<int> ans(n, -1);
    int max_num = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
        if (max_num < v[i])
            max_num = v[i];
    }

    stack_[0] = -1;
    stack_[1] = v[0];
    ans[v[0]] = -1;
    
    for (int i = 1; i < n; i++)
    {
        if (v[i] != stack_[top-1])
        {
            if (ans[v[i]] == -1)
                ans[v[i]] = stack_[top];
            stack_[++top] = v[i];
        }
        else
        {
            top--;
        }
    }

    printf("%d\n", max_num+1);
    for (int i = 0; i <= max_num; i++)
        printf("%d ", ans[i]);

    return 0;
}