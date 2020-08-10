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

int main() {
    vector<int> v;
    
    int input;
    while (cin >> input)
        v.push_back(input);
    
    int size = v.size();
    set<ii> ans;
    for (int i = 0; i < size - 2; i++)
    {
        for (int j = i+1; j < size - 1; j++)
        {
            if (v[i] + v[j] == v[size-1])
                ans.emplace(min(v[i], v[j]), max(v[i], v[j]));
        }
    }
    
    if (ans.size() == 0)
    {
        cout << "0" << endl;
        return 0;
    }
    
    for (auto &si : ans)
        cout << si.first << " " << si.second << endl;
    cout << ans.size() << endl;
    
    return 0;
}