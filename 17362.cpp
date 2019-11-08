#include <iostream>

int finger[] = {2, 1, 2, 3, 4, 5, 4, 3};

int main() {
    int n;
    scanf("%d", &n);
    
    printf("%d", finger[n % 8]);
    return 0;
}