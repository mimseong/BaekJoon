#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector <int> a(2001,0);
    
    for(int i = 0; i < n; i++){
        int input;
        scanf("%d", &input);
        a[input+1000]++;
    }
    
    for(int i = 0;i <= 2000; i++){
        if(a[i] != 0)
            printf("%d ", i-1000);
    }
    
    return 0;
}