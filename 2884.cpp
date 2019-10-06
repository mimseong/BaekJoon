#include <iostream>

int main() {
    int h, m;
    scanf("%d %d", &h, &m);
    
    int sum = h*60 + m - 45;
    if(sum < 45)
        sum += 24*60;
    
    printf("%d %d", (sum)/60%24, (sum)%60);
}