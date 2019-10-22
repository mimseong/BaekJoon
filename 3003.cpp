#include <iostream>

int main() {
    int a1, a2, a3, a4, a5, a6; //킹, 퀸, 룩, 비숍, 나이트, 폰
    scanf("%d %d %d %d %d %d", &a1, &a2, &a3, &a4, &a5, &a6);
    printf("%d %d %d %d %d %d", 1-a1, 1-a2, 2-a3, 2-a4, 2-a5, 8-a6);
}