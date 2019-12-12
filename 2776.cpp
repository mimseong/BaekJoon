#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    
    for(int i = 0; i < t; i++){
        int n, m;
        scanf("%d", &n);
        vector<int> v1(n);
        for(int j = 0; j < n; j++)
            scanf("%d", &v1[j]);
        sort(v1.begin(), v1.end());
        
        scanf("%d", &m);
        for(int j = 0; j < m; j++){
            int input;
            scanf("%d", &input);
            int check = *lower_bound(v1.begin(), v1.end(), input);
            if(check == input)
                printf("1\n");
            else
                printf("0\n");
        }
    }
    
    return 0;
}