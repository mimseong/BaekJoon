#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using i64 = long long;

bool check(vector<int> v, int mid, int money){
    i64 sum = 0;
    
    for(int i = 0; i < v.size(); i++)
        sum += min(v[i], mid);
    
    if(sum <= money)
        return true;
    else
        return false;
}

int main(){
    int n, m;
    scanf("%d", &n);
    vector<int> v(n);
    
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    scanf("%d", &m);

    int low = 1;
    int high = *max_element(v.begin(), v.end()) + 1;
    
    while(true){
        if(low == high -1)
            break;
            
        int mid = (low+high)/2;
        if(check(v, mid, m))
            low = mid;
        else
            high = mid;
    }
    
    printf("%d", low);
    return 0;
}