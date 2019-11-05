#include <iostream>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    if(k == 0){
        printf("1");
        return 0;
    }

    if(k > n/k)
        k = n-k;

    int mul1 = 1, mul2 = 1;

    int count = k;
    for(int i = 0; i < count; i++){
        mul1 *= n--;
        mul2 *= k--;
    }
    printf("%d", mul1/mul2);
    
    return 0;
}