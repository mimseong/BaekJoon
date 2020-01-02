#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    char enter;
    scanf("%d", &n);
    scanf("%c", &enter);
    vector<vector<char>> v(n, vector<char>(n));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%c", &v[i][j]);
        }
        scanf("%c", &enter);
    }
    
    int result = 0;
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(v[i][j] == '.'){
                count++;
                if(count == 2)
                    result++;
            }
            else{
                count = 0;
            }
        }
    }
    
    printf("%d ", result);
    
    result = 0;
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(v[j][i] == '.'){
                count++;
                if(count == 2)
                    result++;
            }
            else{
                count = 0;
            }
        }
    }
    
    printf("%d", result);
}