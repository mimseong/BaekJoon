#include <iostream>

using namespace std;

int main() {
    int hight = 10;
    string str;
    cin >> str;
    
    for(int i = 1; i < str.length(); i++){
        if(str[i-1] == str[i])
            hight += 5;
        else
            hight += 10;
    }
    printf("%d", hight);
}