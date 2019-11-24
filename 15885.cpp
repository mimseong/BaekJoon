#include <iostream>
using namespace std;

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    
    if(a-b > 0){
        printf("%d", 2*(a-b)/b);
    } else {
        printf("%d", -2*(a-b)/b);
    }
    
    return 0;
}