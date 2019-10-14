#include <iostream>

int main() {
    int x;
    scanf("%d", &x);
    
    for(int i = 1; ; i++){
        int num = 1 + i*(i-1)/2;
        if(x < num){
            int index = i - 1;
            int sub = x - num + i - 1;
            
            if((i-1)%2 == 1)
                printf("%d/%d", index-sub, 1+sub);
            else
                printf("%d/%d", 1+sub, index-sub);
            break;
        }
    }
    return 0;
}