#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using i64 = long long;

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("Case #%d: %d + %d = %d\n", i, a, b, a+b);
    }

    return 0;
}