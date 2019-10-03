#include <iostream>

int main() {
    int n;
    scanf("%d", &n);
    switch(n % 8){
        case 1:
            printf("1");
            break;
        case 2: case 0:
            printf("2");
            break;
        case 3: case 7:
            printf("3");
            break;
        case 4: case 6:
            printf("4");
            break;
        case 5:
            printf("5");
            break;
    }
}