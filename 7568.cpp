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
 
using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;
 
int main(){
    int n;
    scanf("%d", &n);
    
    vector<ii> v(n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &v[i].xx, &v[i].yy);
    
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if ((v[j].xx > v[i].xx) && (v[j].yy > v[i].yy))
                count++;
        }
        cout << count + 1 << " ";
    }
    
    return 0;
}