#include <iostream>
#include <algorithm>

using namespace std;
using i64 = long long;

int main() {
    i64 a, l;
    scanf("%lld %lld", &a, &l);
    printf("%lld", (max(a, l) - min(a, l) + 1)*(a+l)/2);
}