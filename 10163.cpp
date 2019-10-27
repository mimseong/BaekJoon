#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector <int>> v(101, vector<int> (101, 0));
    int n;
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++){
        int x, y, lenx, leny;
        scanf("%d %d %d %d", &x, &y, &lenx, &leny);
        for(int j=y; j < y+leny; j++){
            for(int k=x; k < x+lenx; k++){
                v[k][j] = i;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        int count = 0;
        
        for(int j = 0; j <= 100; j++){
            for(int k = 0; k <= 100; k++){
                if(v[j][k] == i)
                    count++;
            }
        }
        
        printf("%d\n", count);
    }
    return 0;
}