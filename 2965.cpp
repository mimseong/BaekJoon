#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d", max(b-a-1, c-b-1));
}