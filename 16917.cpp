#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, c, x, y;
    scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
    
    int m = a*x + b*y;

    for(int i = 2; (i/2) <= max(x, y); i += 2)
        m = min(c*i + a*(max(0, x-i/2)) + b*(max(0, y-i/2)), m);
    
    printf("%d", m);
}