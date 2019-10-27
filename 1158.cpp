#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    vector <int> v;
    vector <int> p;
    scanf("%d %d", &n, &k);
    
    for(int i = 1; i <= n; i++)
        v.push_back(i);
    
    int pos = 0;    //현위치
    while (!v.empty()){
        pos = (pos + k - 1) % v.size();
        p.push_back(v[pos]);
        v.erase(v.begin() + pos);
    }
    
    printf("<%d", p[0]);
    for(int i = 1; i < n; i++)
        printf(", %d", p[i]);
    printf(">");
    
    
    return 0;
}