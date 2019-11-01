#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int l, a, b, c, d;
    scanf("%d %d %d %d %d", &l, &a, &b, &c, &d);
    
    printf("%d", l - max((a + c - 1)/c, (b + d - 1)/d));
    
    return 0;
}