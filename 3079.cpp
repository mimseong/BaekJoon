#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using i64 = long long;

bool check(i64 mid, int m, vector<i64> v){
    i64 count = 0;
    for(int i = 0; i < v.size(); i++){
        count += mid / v[i];
    }
    if(count >= m)
        return true;
    return false;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<i64> v(n);
    
    for(int i = 0; i < n; i++)
        scanf("%lld", &v[i]);
    
    i64 low = 0;
    i64 high = *max_element(v.begin(), v.end())*m;
    
    while(true){
        if(low + 1 == high)
            break;
        i64 mid = (low + high)/2;
        if(check(mid, m, v))
            high = mid;
        else
            low = mid;
    }
    
    printf("%lld", high);
    
}