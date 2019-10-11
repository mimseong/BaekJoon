#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    int n, a;
    scanf("%d", &n);
    
    
    for(int i = 1; i <= n; i++){
        scanf("%d", &a);
        v.insert(v.end()-a, i);
    }
    
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    
    return 0;
}