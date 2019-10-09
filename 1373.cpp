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
    int sum = 0;
    
    for(int i = 0; i < str.length(); i++){
        if(i%3 == 0)
            sum += 4*(str[i] - '0');
        else if(i%3 == 1)
            sum += 2*(str[i] - '0');
        else{
            sum += (str[i] - '0');
            result += (sum + '0');
            sum = 0;
        }
    }
    cout << result;
}