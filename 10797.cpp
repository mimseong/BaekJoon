#include <iostream>

int main() {
    int day;
    int car;
    int count = 0;
    
    scanf("%d", &day);
    
    for(int i = 0; i < 5; i++){
        scanf("%d", &car);
        if(car == day)
            count++;
    }
    printf("%d", count);
}