#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector <int> a(10001, 0); 
    
    for(int i = 0; i < n; i++){
        int input;
        scanf("%d", &input);
        a[input]++;
    }
    for(int i = 1; i < 10001; i++){
        if(a[i] != 0){
            for(int j = 0; j < a[i]; j++)
                printf("%d\n", i);
        }
    }
    
    return 0;
}