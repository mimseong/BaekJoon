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
    
    int count = 1;
    for(int i = 0; ; i++,count++){
        if(i == v.size())
            i = 0;
            
        if(count == k){
            p.push_back(v[i]);
            v.erase(v.begin() + i);
            i--;
            count = 0;
        }
        
        if(v.empty())
            break;
    }
    
    printf("<%d", p[0]);
    for(int i = 1; i < n; i++)
        printf(", %d", p[i]);
    printf(">");
    
    
    return 0;
}