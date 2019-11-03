#include <iostream>

int main() {
    int n, sum = 0;
    char str[101];
    scanf("%d %s", &n, str);
    
    for(int i = 0; i < n; i++)
        sum += str[i] - '0';
    printf("%d", sum);
    
    return 0;
}