#include <iostream>

int main() {
    int h, m, s, t;
    scanf("%d %d %d %d", &h, &m, &s, &t);
    
    s += t;
    m += s / 60;
    h += m / 60;
    
    printf("%d %d %d", h%24, m%60, s%60);
    
    return 0;
}