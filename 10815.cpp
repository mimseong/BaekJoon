#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector <int> v(n);
    
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
        
    sort(v.begin(), v.end());
    
    int m;
    scanf("%d", &m);
    
    for(int i = 0; i < m; i++){
        int input;
        scanf("%d", &input);
        int tmp = *lower_bound(v.begin(), v.end(), input);
        if(tmp == input)
            printf("1 ");
        else
            printf("0 ");
    }
    
    return 0;
}