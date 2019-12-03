#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector <int> v(n);
    
    
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    
    int l=0, r=0;
    int ans = 0;
    int sum = v[r];
    
    while(r < n){
        if(sum <= m){
            if(m == sum)
                ans++;
            r++;
            sum += v[r];
        }
        else{
            sum -= v[l];
            l++;
        }
    }
    
    printf("%d", ans);
    
    return 0;
}