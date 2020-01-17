#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using i64 = long long;

int main() {
    i64 m, n;
    while(scanf("%lld %lld", &m, &n) == 2){
        vector<i64> v(n);
        
        m *= 10000000;
        
        for(int i = 0; i < n; i++){
            scanf("%lld", &v[i]);
        }
        sort(v.begin(), v.end());
        
        if(n == 1 || n==0){
            printf("danger\n");
            continue;
        }
        
        int l = 0, r = n-1;
        i64 sum;
        
        while(l < r){
            sum = v[l]+v[r];
            
            if(sum > m){
                r--;
            }
            else if(sum < m){
                l++;
            }
            else
                break;
        }
        
        if(sum == m)
            printf("yes %lld %lld\n", v[l], v[r]);
        else
            printf("danger\n");
    }

    return 0;
}