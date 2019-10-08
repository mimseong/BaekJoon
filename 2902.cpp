#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;
    
    for(int i = 0; i < str.length(); i++){
        if(i == 0)
            printf("%c", str[0]);
        if(str[i] == 45)
            printf("%c", str[i+1]);
    }
}