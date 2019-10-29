#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    
    for(int i = 0; i < t; i++){
        int m, n;
        scanf("%d %d", &m, &n);
        vector<int> sum(n, 0);
        vector<int> count(n, 0);
        
        for(int j = m; j>0; j--){
            for(int k = 0; k<n; k++){
                int input;
                scanf("%d", &input);
                if(input == 1){
                    sum[k] += j;
                    count[k]++;
                }
            }
        }
        int result = 0;
        for(int j = 0; j < n; j++)
            result += sum[j] - count[j]*(count[j]+1)/2;
        printf("%d\n", result);
        
    }
    
    return 0;
}