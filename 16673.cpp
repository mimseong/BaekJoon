#include <iostream>

int main() {
    int n, k, p;
    scanf("%d %d %d", &n, &k, &p);
    printf("%d", k*n*(n+1)/2 + p*n*(n+1)*(2*n + 1)/6);
}