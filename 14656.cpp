#include <iostream>

int main() {
    int n, number;
    int count = 0;
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++){
        scanf("%d", &number);
        if(number != i)
            count++;
    }
    printf("%d", count);
}