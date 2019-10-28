#include <iostream>

int main() {
    int sum;
    scanf("%d", &sum);
    bool less100 = true;
    
    for(int i = 1; i < 10; i++){
        int num;
        scanf("%d", &num);
        
        if(sum + num >= 100){
            if(100-sum >= sum + num -100)
                printf("%d", sum + num);
            else
                printf("%d", sum);
            less100 = false;
            break;
        }
        sum += num;
    }
    if(less100)
        printf("%d", sum);
    
    return 0;
}