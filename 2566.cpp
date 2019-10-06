#include <iostream>

int main() {
    int num, max = -1;
    int x, y;
    
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            scanf("%d", &num);
            if(num > max){
                max = num;
                x = i; y = j;
            }
        }
    }
    printf("%d\n%d %d", max, x, y);
}