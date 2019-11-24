#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    
    for(int i = 0; i < t; i++){
        double n;
        scanf("%lf", &n);
        printf("%d\n", (int)sqrt(n));
    }
}