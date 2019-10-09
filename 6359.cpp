#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    double n;
    scanf("%d", &t);
    
    for(int i = 0; i < t; i++){
        scanf("%lf", &n);
        printf("%d\n", (int)sqrt(n));
    }
}