#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector <string>v1(n);
    vector <string>v2(m);
    for(int i = 0; i < n; i++)
        cin >> v1[i];
    for(int i = 0; i < m; i++)
        cin >> v2[i];
        
    v1.insert(v1.end(), v2.begin(), v2.end());
        
    sort(v1.begin(), v1.end());
    
    int count = 0;
    for(int i = 0; i < n+m; i++){
        if(v1[i] == v1[i+1])
            count++;
    }
    printf("%d\n", count);
    for(int i = 0; i < n+m; i++){
        if(v1[i] == v1[i+1])
            cout << v1[i] << endl;
    }

    return 0;
}