#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <cstring>
#include <map>
#define xx first
#define yy second
#define MAX 1e9
 
using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;


int main() 
{
    int x, y;
    scanf("%d %d", &x, &y);

    int lo = 1;
    int hi = MAX;
    int ans = (int)(y / x * 100);

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;

        if (mid == ans + 1)
        {
            lo = mid + 1;
            ans = mid;
        }
        else
        {
            hi = mid - 1;
        }
    }

    cout << mid;


    return 0;
}