#include <iostream>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    
    int repeat = n / 2;
    
    if (n % 2 == 1) {
        printf("1 2 -3 ");
        repeat -= 1;
    }
    
    for (int i = 0; i < repeat; i++) {
        printf("%d %d ", i + 4, -(i + 4));
    }
    
    printf("0");
}