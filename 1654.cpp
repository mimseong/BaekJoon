#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using i64 = long long;

bool cut(i64 mid, int n, vector<i64> v){
    i64 sum = 0;
    
    for(int i = 0; i < v.size(); i++)
        sum += v[i] / mid;
    if(sum >= n)
        return true;
    else
        return false;
}

int main() {
    int k, n;
    scanf("%d %d", &k, &n);
    vector<i64> v(k);
    
    for(int i = 0; i < k; i++)
        scanf("%lld", &v[i]);
        
    i64 low = 1;
    i64 high = *max_element(v.begin(), v.end()) + 1;
        
    while (true){
        if(low == high -1)
            break;
        i64 mid = (low+high)/2;
        if(cut(mid, n, v))
            low = mid;
        else
            high = mid;
    }
    
    printf("%lld", low);
        
    return 0;
}