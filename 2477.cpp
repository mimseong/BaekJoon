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
 
int main() {
    int n;
    scanf("%d", &n);
    
    vector<ii> v(6);
    vector<int> count(5);
    for (int i = 0; i < 6; i++)
    {
      scanf("%d %d", &v[i].xx, &v[i].yy);
      count[v[i].xx]++;
    }
    
    int start;
    for (int i = 0; i < 6; i++)
    {
        if (count[v[i].xx] == 1 && count[v[(i + 1) % 6].xx] == 1)
            start = i;
    }
    
    cout << (v[start].yy * v[(start + 1) % 6].yy - v[(start - 2 + 6) % 6].yy * v[(start - 3 + 6) % 6].yy) * n << endl;
    
    
    
    return 0;
}