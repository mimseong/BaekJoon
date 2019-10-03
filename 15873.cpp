#include <iostream>

int main() {
    int n;
    scanf("%d", &n);
    if(100 > n)
        printf("%d", n/10 + n%10);
    else if(n % 10 == 0)
        printf("%d", n/100 + 10);
    else
        printf("%d", n%100 + 10);
}