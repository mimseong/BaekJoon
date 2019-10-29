#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a0, a1, a2, a3;
    int b0, b1, b2, b3;
    
    scanf("%d %d %d %d", &a0, &a1, &a2, &a3);
    scanf("%d %d %d %d", &b0, &b1, &b2, &b3);
    
    printf("%d", max(a0+a1+a2+a3, b0+b1+b2+b3));
}