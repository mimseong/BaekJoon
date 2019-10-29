#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int h1, h2, h3;
    int d1, d2;
    scanf("%d %d %d", &h1, &h2, &h3);
    scanf("%d %d", &d1, &d2);
    
    printf("%d", min({h1, h2, h3}) + min(d1, d2) - 50);
}