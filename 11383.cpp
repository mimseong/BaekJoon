#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<string> v(n, "");
    
    for(int i = 0; i < n; i++){
        string input;
        cin >> input;
        for(int j = 0; j < m; j++){
            v[i] += input[j]; v[i] += input[j];
        }
    }
    
    bool isElfa = true;
    for(int i = 0; i < n; i++){
        string input;
        cin >> input;
        if(input != v[i]){
            isElfa = false;
            break;
        }
    }
    if(isElfa)
        printf("Eyfa");
    else
        printf("Not Eyfa");
    
    return 0;
}