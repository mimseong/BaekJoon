#include <iostream>

int main() {
    int n;
    scanf("%d", &n);
    
    if(n == 1){
        printf("1");
        return 0;
    }
    
    int max = 1, min = -4;
    if(min <= n - 6 && n - 6 <= max){
        printf("2");
        return 0;
    }
    
    for(int i = 1; ; i++){
        max += 6*i;
        min += 6*(i-1);
        if(min <= (n - 6*(i+1)) && (n - 6*(i+1)) <= max){
            printf("%d", i+2);
            break;
        }
    }
    
    return 0;
}