#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    
    for(int i = 0; i < n; i++){
        int tmp;
        scanf("%d", &tmp);
        v[i] = tmp;
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++)
        printf("%d\n", v[i]);
    
    return 0;
}