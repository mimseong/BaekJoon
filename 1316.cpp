#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using i64 = long long;

int solve()
{
    string s;
    cin >> s;
    
    s.erase(unique(s.begin(), s.end()), s.end());
    string s2 = s;
    
    sort(s2.begin(), s2.end());
    s2.erase(unique(s2.begin(), s2.end()), s2.end());

    if (s2.size() != s.size())
        return 0;
    return 1;
}

int main(){
    int n;
    scanf("%d", &n);
    
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count += solve();
    }
    
    cout << count;
    
    return 0;
}