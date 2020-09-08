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
#pragma warning(disable:4996)
 
using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;
 
int main() {
    
    int n;
    scanf("%d", &n);
    
    vector<string> str(n);
    for (int i = 0; i < n; i++)
        cin >> str[i];
    
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            string str1 = str[i];
            string str2 = str[j];
            
            if (str1.size() != str2.size())
                continue;
            
            vector<int> alpha1(26, -1);
            vector<int> alpha2(26, -1);
            
            bool is_shong = true;
            for (int k = 0; k < str1.size(); k++)
            {
                if (alpha1[str1[k] - 'a'] == -1 && alpha2[str2[k] - 'a'] == -1)
                {
                    alpha1[str1[k] - 'a'] = str2[k] - 'a';
                    alpha2[str2[k] - 'a'] = str1[k] - 'a';
                    continue;
                }
                
                if (alpha1[str1[k] - 'a'] != str2[k] - 'a' ||
                    alpha2[str2[k] - 'a'] != str1[k] - 'a')
                {
                    is_shong = false;
                    break;
                }
            }
            
            if (is_shong)
                ans++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}