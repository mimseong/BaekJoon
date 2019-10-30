#include <iostream>

int main() {
    int t;
    scanf("%d", &t);
    
    if(t % 10 != 0){
        printf("-1");
        return 0;
    }
    printf("%d ", t / 300);
    t %= 300;
    printf("%d ", t / 60);
    t %= 60;
    printf("%d", t/10);
    
    return 0;
}