#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int K, N, M;
    scanf("%d %d %d", &K, &N, &M);
    printf("%d", max(0, K*N-M));
}