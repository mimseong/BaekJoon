#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    if(a == b && b == c)
        printf("%d", 10000 + a*1000);
    else if(a == b || b == c )
        printf("%d", 1000 + b*100);
    else if(c == a)
        printf("%d", 1000 + a*100);
    else
        printf("%d", max({a, b, c})*100);
    
    return 0;
}