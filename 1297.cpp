#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c, result;
    scanf("%lf %lf %lf", &c, &a, &b);
    
    result = sqrt(c*c / (a*a + b*b));
    printf("%d %d", (int)(a*result), (int)(b*result));
}