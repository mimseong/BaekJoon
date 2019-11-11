#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using i64 = long long;

bool check(i64 mid, int n, vector<int> v){
    i64 c = 0;
    for(int i = 0; i < v.size(); i++)
        c += (v[i] + mid - 1) / mid;
    if(c <= n)
        return true;
    return false;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> v(m);
    
    for(int i = 0; i < m; i++){
        scanf("%d", &v[i]);
    }
    
    int low = 0;
    i64 high = *max_element(v.begin(), v.end());
    
    while(true){
        if(low + 1 == high)
            break;
        i64 mid = (low + high) / 2;
        
        if(check(mid, n, v))
            high = mid;
        else
            low = mid;
    }
    printf("%lld", high);
    
    return 0;
}