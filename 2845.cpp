#include <iostream>

int main() {
    int L, P;
    int a1, a2, a3, a4, a5;
    scanf("%d %d", &L, &P);
    scanf("%d %d %d %d %d", &a1, &a2, &a3, &a4, &a5);
    printf("%d %d %d %d %d", a1-L*P, a2-L*P, a3-L*P, a4-L*P, a5-L*P);
}