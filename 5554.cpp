#include <iostream>

int main() {
    int a1, a2, a3, a4;
    int total;
    scanf("%d %d %d %d", &a1, &a2, &a3, &a4);
    total = a1 + a2 + a3 + a4;
    printf("%d\n%d", total/60, total%60);
}