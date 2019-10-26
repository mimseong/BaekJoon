#include <iostream>

int main() {
    int a, b;
    int tmp1, tmp2, tmp3;
    
    scanf("%d %d", &a, &b);
    tmp3 = a * (b/100);
    b -= b/100 * 100;
    tmp2 = a * (b/10);
    tmp1 = a * (b%10);
    
    printf("%d\n", tmp1);
    printf("%d\n", tmp2);
    printf("%d\n", tmp3);
    printf("%d", tmp3*100 + tmp2*10 + tmp1);
}