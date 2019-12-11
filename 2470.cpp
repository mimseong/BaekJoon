#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using i64 = long long;

i64 absF(i64 n){
    if(n < 0)
        n *= -1;
    return n;
}


int main() {
    int n;
    scanf("%d", &n);
    vector <int> v(n);
    
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    
    sort(v.begin(), v.end());
    
    int l=0, r=n-1;
    int saveL = l, saveR = r;
    i64 sum = (i64)v[l]+v[r];
    i64 minSum = sum;
    
    while(l+1 != r){
        
        if(sum < 0)
            l++;
        else if(sum > 0)
            r--;
        else {
            saveL = l, saveR = r;
            break;
        }
        
        if(absF(minSum) > absF((i64)v[l]+v[r])){
            saveL = l, saveR = r;
            minSum = (i64)v[l]+v[r];
        }
        sum = (i64)v[l]+v[r];
        
    }
    
    printf("%d %d", v[saveL], v[saveR]);
    
    return 0;
}