#include <iostream>
#include <algorithm>
using namespace std;
using i64 = long long;

int a[1000000];

int main() {
    int a1, a2, a3, a4; //내린 사람
    int b1, b2, b3, b4; //탄 사람
    scanf("%d %d %d %d %d %d %d %d", &a1, &b1, &a2, &b2, &a3, &b3, &a4, &b4);
    
    int max = b1;
    int sum = b1;
    sum += b2 - a2;
    if(sum > max)
        max = sum;
    sum += b3 - a3;
    if(sum > max)
        max = sum;   
    printf("%d", max);
}