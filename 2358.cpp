#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    map<int, int> mx;
    map<int, int> my;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        mx[x]++;
        my[y]++;
    }
    
    int cnt = 0;
    
    for (auto mi : mx)
    {
        //cout << mi.first << " " << mi.second << endl;
        if (mi.second >= 2)
            cnt++;
        
    }
    
    for (auto mi : my)
    {
        // cout << mi.first << " " << mi.second << endl;
        if (mi.second >= 2)
            cnt++;
    }
    
    cout << cnt << endl;
    
}