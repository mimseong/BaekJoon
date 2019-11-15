#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using i64 = long long;

bool cut(int mid,int m, vector<int> v){
    i64 sum = 0;
    
    for(int i = 0; i < v.size(); i++)
        sum += max(0, v[i]-mid);
    if(sum >= m)
        return true;
    else
        return false;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> v(n);
    
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
        
    int low = 0;
    int high = *max_element(v.begin(), v.end());
        
    while (true){
        if(low == high-1)
            break;
        int mid = (low+high)/2;
        if(cut(mid, m, v))
            low = mid;
        else
            high = mid;
    }
    
    printf("%d", low);
        
    return 0;
}