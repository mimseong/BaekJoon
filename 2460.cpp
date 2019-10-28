#include <iostream>

int main() {
    int max = 0;
    int now = 0;
    
    for(int i = 0; i < 10; i++){
        int in, out;
        scanf("%d %d", &out, &in);
        now = in - out + now;
        if(now > max)
            max = now;
    }
    
    printf("%d", max);
    return 0;
}