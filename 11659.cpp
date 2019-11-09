#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> v(n+1, 0);
    
    v[0] = 0;
    for(int i = 1; i <= n ; i++){
        scanf("%d", &v[i]);
        v[i] += v[i-1];
    }
    
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", v[b]-v[a-1]);
    }
    
    return 0;
}