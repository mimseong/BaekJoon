#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v(9);
    for(int i = 0; i < 9; i++)
        scanf("%d", &v[i]);
        
    int sum = accumulate(v.begin(), v.end(), 0), sum2;
    int diff = sum - 100;
    
    for(int i = 0; i < 8; i++){
        for(int j = i + 1; j < 9; j++){
            sum2 = v[i] + v[j];
            if(sum2 == diff){
                v.erase(v.begin() + j);
                v.erase(v.begin() + i);
            }
        }
    }
    
    sort(v.begin(), v.end());
    for(int i = 0; i < 7; i++)
        printf("%d\n", v[i]);
    
}