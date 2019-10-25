#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a;
    int sum = 0;
    
    for(int i  = 0; i < 5; i++){
        scanf("%d", &a);
        sum += max(40, a);
    }
    printf("%d", sum/5);
}