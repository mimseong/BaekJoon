#include <iostream>

using i64 = long long;

int main() {
    i64 a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld", (a+b)*(a-b));
}