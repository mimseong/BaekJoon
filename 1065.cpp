#include <iostream>
#include <string>
using namespace std;

bool isHan(int n){
    string s = to_string(n);
    
    int min = s[1]-s[0];
    
    for(int i = 1; i < s.size()-1; i++){
        if((s[i+1]-s[i]) != min)
            return false;
    }
    
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(isHan(i))
            count++;
    }
    
    printf("%d\n", count);
    
    return 0;
}s