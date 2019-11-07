#include <iostream>

int main() {
    int n;
    int count = 0;
    scanf("%d", &n);
    
    for(int i = 1; (n - 2*i) > 3; i++){
        count += (n - 2*i -2) / 2;
    }
    printf("%d", count);
}