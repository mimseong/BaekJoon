#include <iostream>
using i64 = unsigned long long;
int main() {
    i64 n;
    i64 sum = 0;
    scanf("%lld", &n);
    
    for(i64 i = 1; i < n; i++){
        sum += i*n + i;
    }
    
    printf("%llu", sum);
    return 0;
}