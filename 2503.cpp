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
    int t;
    scanf("%d", &t);

    vector<bool> v(1000, true);

    for (int i = 123; i <= 999; i++)
    {
    	string s = to_string(i);
    	if (s[0] == s[1] || s[2] == s[1] || s[0] == s[2])
    	    v[i] = false;
    	if (s[0] - '0' == 0 || s[1] - '0' == 0 || s[2] - '0' == 0)
    	    v[i] = false;
    }

    for (int k = 0; k < t; k++)
    {
        int n, sn, bn;
        scanf("%d %d %d", &n, &sn, &bn);
        
        string s = to_string(n);
        
        for (int i = 123; i <= 999; i++)
        {
            if (!v[i])
                continue ;
            
            int ball = 0, strike = 0;
            string tmps = to_string(i);
            
            for (int a = 0; a < 3; a++)
            {
                for (int b = 0; b < 3; b++)
                {
                    if (a==b && s[a] == tmps[b]) 
                        strike++;
                    if (a!=b && s[a] == tmps[b])
                        ball++;
                }
            }
            if (strike != sn || ball != bn)
                v[i] = false;
            
        }
    }
    
    int ans = 0;
    for (int i = 123; i <= 999; i++)
    {
        if (v[i])
            ans++;
    }
    cout << ans << endl;
    
    return 0;
}