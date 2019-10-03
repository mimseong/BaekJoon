#include <iostream>

int main() {
    int month, day;
    scanf("%d %d", &month, &day);
    //printf("%d %d", month, day);
    
    if(month > 2)
        printf("After");
    else if(month < 2)
        printf("Before");
    else{
        if(day < 18)
            printf("Before");
        else if(day > 18)
            printf("After");
        else
            printf("Special");
    }
}