#include <iostream>

int main() {
    int m, n;
    int min;
    bool first = false;
    int sum = 0;
    
    scanf("%d %d", &m, &n);
    
    for(int i = 1; i*i <= n; i++){
        if(m <= i*i){
            if(!first){
                min = i*i;
                first = true;
            }
            sum += i*i;
        }
    }
    if(sum == 0)
        printf("-1");
    else
        printf("%d\n%d", sum, min);
}