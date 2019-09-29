#include <iostream>

int main() {
    int hour, minute, time;
    scanf("%d %d %d", &hour, &minute, &time);
    
    hour += (minute + time) / 60;
    minute = (minute + time) % 60;
    printf("%d %d", hour % 24, minute);
}