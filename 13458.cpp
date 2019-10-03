#include <iostream>
#include <algorithm>
using namespace std;
using i64 = long long;

int a[1000000];

int main() {
    int n, b, c;
    i64 sum = 0;
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d %d", &b, &c);
    
    for(int i = 0; i < n; i++)
        sum += ((max(a[i]-b, 0)+c-1)/c + 1);
    printf("%lld", sum);
}