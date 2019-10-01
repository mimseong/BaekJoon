#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c, d, p;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &p);
    int coast_x = p * a;
    int coast_y = b;
    if(p > c)
        coast_y += d * (p - c);
    printf("%d", min(coast_x, coast_y));
}