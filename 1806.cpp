#include <iostream>
#include <vector>
using namespace std;
using i64 = long long;

int main() {
    int n, s;
    scanf("%d %d", &n, &s);
    vector<int> v(n);
    
    i64 allSum = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
        allSum += v[i];
    }
    
    int l = 0, r = 0;
    int ans = n;
    int count = 1;
    i64 sum = v[0];
    
    while(l < n){
        if(sum < s){
            if(r == n-1)
                break;
            sum += v[++r];
            count++;
        }
        else {
            if(count < ans)
                ans = count;
            sum -= v[l++];
            count--;
        }
    }
    if(allSum < s)
        printf("0");
    else
        printf("%d", ans);
    
    return 0;
}