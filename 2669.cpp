#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> v(100, vector<int>(100, 0));
    
    for(int k = 0; k < 4; k++){
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        for(int i = x1; i < x2; i++){
            for(int j = y1; j < y2; j++){
                v[i][j] = 1;
            }
        }
        
    }
    
    int result = 0;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(v[i][j] == 1)
                result++;
        }
    }
    
    printf("%d", result);
    
    return 0;
}