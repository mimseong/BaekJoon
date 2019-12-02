#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> v(n);
    
    scanf("%d", &v[0]);
    for(int i = 1; i < n; i++){
        scanf("%d", &v[i]);
        v[i] += v[i-1];
    }
    
    for(int i = 0; i < m; i++){
        int input;
        scanf("%d", &input);
        printf("%d\n", upper_bound(v.begin(), v.end(), input)-v.begin());
    }
    
    return 0;
}