#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> v(m);
    
    for(int i = 0; i < m; i++)
        scanf("%d", &v[i]);
    
    sort(v.begin(), v.end(), greater<int>());
        
    int max = v[0];
    int money = v[0];
    for(int i = 1; i < min(n, m); i++){
        int tmp = v[i] * (i+1);
        if(max < tmp){
            max = tmp;
            money = v[i];
        }
    }
    printf("%d %d", money, max);
    
    return 0;
}