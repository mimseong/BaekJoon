#include <iostream>

int main() {
    int a;
    int sum = 0;
    
    for(int i  = 0; i < 5; i++){
        scanf("%d", &a);
        if(a < 40)
            a = 40;
        sum += a;
    }
    printf("%d", sum/5);
}