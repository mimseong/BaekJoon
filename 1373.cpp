#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;
    if ((3 - (str.length() % 3)) == 1)
        str = "0" + str;
    else if ((3 - (str.length() % 3)) == 2)
        str = "00" + str;
        
    string result = "";
    
    for(int i = 0; i < str.length(); i += 3){
        int d = 4 * str[i] + 2 * str[i + 1] + str[i+2] - 7 * '0';
        result += d + '0';
    }
    cout << result;
}