#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int l, a, b, c, d;
    scanf("%d %d %d %d %d", &l, &a, &b, &c, &d);
    
    printf("%d", l - max(a/c + max(a%c>0?1:0,0), b/d + max(b%d>0?1:0,0)));
    
    return 0;
}