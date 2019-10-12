#include <iostream>

using namespace std;

int main() {
    int n, p1, p2, max = 0, sum = 0;
    scanf("%d %d", &n, &p1);
    
    for(int i = 0; i < n; i++){
        scanf("%d", &p2);
        if(p1 < p2)
            sum += p2-p1;
        else{
            if(sum > max)
                max = sum;
            sum = 0;
        }
        p1 = p2;
    }
    printf("%d", max);
    return 0;
}