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
        int tmp = upper_bound(v.begin(), v.end(), input) - lower_bound(v.begin(), v.end(), input);
        printf("%d ", tmp);
    }
    
    return 0;
}