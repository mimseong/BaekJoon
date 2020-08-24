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
 
using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;



void solve()
{
    ii a1, a2, b1, b2;
    cin >> a1.xx >> a1.yy >> a2.xx >> a2.yy;
    cin >> b1.xx >> b1.yy >> b2.xx >> b2.yy;
    
    bool x = false, y = false;
    
    if (max(a1.xx, b1.xx) < min(a2.xx, b2.xx))
        x = true;
    if (max(a1.yy, b1.yy) < min(a2.yy, b2.yy))
        y = true;
    
    if (((a1.xx == b2.xx) && (a1.yy == b2.yy)) || ((a2.xx == b1.xx) && (a1.yy == b2.yy)) || ((a1.xx == b2.xx) && (a2.yy == b1.yy)) || ((a2.xx == b1.xx) && (a2.yy == b1.yy)))
        printf("c\n");
    else if (x && y)
        printf("a\n");
    else if ((y && ((a2.xx == b1.xx) || (a1.xx == b2.xx))) || (x && ((b1.yy == a2.yy) || (a1.yy == b2.yy))))
        printf("b\n");
    else
        printf("d\n");
}

int main() {
    
    for (int i = 0; i < 4; i++)
        solve();
    
    return 0;
}