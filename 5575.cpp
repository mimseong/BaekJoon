#include <iostream>

int main() {
    int ah, am, as;
    int bh, bm, bs;
    int time1, time2;
    
    for(int i = 0; i < 3; i++){
    scanf("%d %d %d", &ah, &am, &as);
    scanf("%d %d %d", &bh, &bm, &bs);
    
    time1 = ah*3600 + am*60 + as;
    time2 = bh*3600 + bm*60 + bs;
    
    printf("%d %d %d\n", (time2 - time1)/3600, (time2 - time1)%3600/60, (time2 - time1)%3600%60);
    }
}