#include <iostream>
#include <vector>
using namespace std;
using i64 = long long;
int main() {
    int n;
    scanf("%d", &n);
    vector<bool>v(n+1, true);
    vector<i64>prime;
    
    if(n == 1){
        printf("0");
        return 0;
    }
    
    for(int i = 2; i*i <= n; i++){
        if(v[i]){
            for(int j = i*i; j <= n; j+=i)
                v[j] = false;
        }
    }
    
    for(int i = 2; i <= n; i++){
        if(v[i])
            prime.push_back(i);
    }
    
    int l = 0, r = 0;
    int ans = 0;
    i64 count = prime[0];
    
    while(l < prime.size()){
        if(count<n){
            if(r == prime.size()-1)
                break;
            count += prime[++r];
        }
        else if(n<count)
            count -= prime[l++];
        else{
            ans++;
            count -= prime[l++];
        }
    }
    
    printf("%d", ans);
    
    return 0;
}