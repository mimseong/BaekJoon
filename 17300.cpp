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
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

vector<ii> v[10];

int     main()
{
    int n;
    scanf("%d", &n);
    
    vector<int> in(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &in[i]);

    vector<int> check_dup(10);
    v[1].emplace_back(2, 3);
    v[1].emplace_back(5, 9);
    v[1].emplace_back(4, 7);
    
    v[2].emplace_back(5, 8);
    
    v[3].emplace_back(2, 1);
    v[3].emplace_back(5, 7);
    v[3].emplace_back(6, 9);
    
    v[4].emplace_back(5, 6);
    
    v[6].emplace_back(5, 4);
    
    v[7].emplace_back(4, 1);
    v[7].emplace_back(5, 3);
    v[7].emplace_back(8, 9);
    
    v[8].emplace_back(5, 2);
    
    v[9].emplace_back(5, 1);
    v[9].emplace_back(6, 3);
    v[9].emplace_back(8, 7);
    
    for (int i = 0; i < n; i++)
    {
        if (check_dup[in[i]] == 1)
        {
            printf("NO\n");
            return 0;
        }
        
        if (i == n - 1)
            break;
        
        for (int j = 0; j < v[in[i]].size(); j++)
        {
            if (in[i + 1] == v[in[i]][j].yy && check_dup[v[in[i]][j].xx] == 0)
            {
                printf("NO\n");
                return 0;
            }
        }
        check_dup[in[i]] = 1;
    }
    printf("YES\n");
    
    return 0;
}