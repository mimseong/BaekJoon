#include <iostream>

int month_day[12] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
char week[7][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

int main() {
    int month, day;
    scanf("%d %d", &month, &day);
    
    for(int i = 0; i < 11; i++)
        month_day[i+1] += month_day[i];
    
    int sum_day = month_day[month - 1] + day;
    printf("%s", week[sum_day % 7]);
    
    return 0;
}