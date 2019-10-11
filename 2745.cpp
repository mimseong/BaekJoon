#include <iostream>

using namespace std;

int main() {
    string str;
    int num = 0, mul = 1, b;
    cin >> str >> b;
    
    for(int i = str.length() - 1; i >= 0; i--){
        if('A' <= str[i] && str[i] <= 'Z')
            num += ((str[i] - 'A') + 10) * mul;
        else
            num += (str[i] - '0') * mul;
        mul *= b;
    }
    
    printf("%d", num);
}