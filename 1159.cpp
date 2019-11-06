#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(27, 0);
    
    for(int i = 0; i < n; i++){
        string input;
        cin >> input;
        v[input[0]-97]++;
    }
    
    bool no = true;
    for(int i = 0; i < 27; i++){
        if(v[i] >= 5){
            printf("%c", i+97);
            no = false;
        }
    }
    if(no)
        printf("PREDAJA");
}