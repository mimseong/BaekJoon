#include <iostream>

int main() {
    int n, init, sum, i;
    scanf("%d", &n);
    init = n;

    for(i = 1; ; i++){
        sum = n/10 + n%10;
        n = (n%10)*10 + sum%10;
        if(n==init)
            break;
    }
    printf("%d", i);
}