#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<pair<int, int>> v(9);
    
    for(int i = 0; i < 9; i++){
        scanf("%d", &v[i].first);
        v[i].second = i+1;
    }
    sort(v.begin(), v.end());
    
    printf("%d\n%d", v[8].first, v[8].second);
    
    
    return 0;
}