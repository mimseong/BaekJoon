#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using i64 = long long;

bool check(int mid, int c, vector<i64> v){
    int count = 1;
    i64 before = v[0];
    
    for(int i = 1; i < v.size(); i++){
        if(v[i] - before >= mid){
            count++;
            before = v[i];
        }
    }
    if(count >= c)
        return true;
    return false;
}

int main() {
    int n, c;
    scanf("%d %d", &n, &c);
    vector<i64> v(n);
    
    for(int i = 0; i < n; i++)
        scanf("%lld", &v[i]);
    sort(v.begin(), v.end());
    
    i64 low = 1;
    i64 high = v[n-1] - v[0] + 1;
    
    while(true){
        if(low == high - 1)
            break;
        i64 mid = (low + high)/2;
        
        if(check(mid, c, v))
            low = mid;
        else
            high = mid;
    }
    
    printf("%lld", low);
    
}