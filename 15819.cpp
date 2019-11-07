#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, l;
    scanf("%d %d", &n, &l);
    vector <string> v(n);
    for(int i =0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cout << v[l-1];
    
    return 0;
}