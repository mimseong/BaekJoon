#include <iostream>
#include <string>
using namespace std;

int main() {
    string num;
    int cash = 0, tmp;
    cin >> num;
    
    for(int i = num.length() - 1; i >= 0; i--){
        tmp = (num[i] - '0') * 4 + cash;
        num[i] = (tmp % 10) + '0';
        cash = tmp / 10;
    }
    if(cash != 0)
        cout << cash;
    cout << num;
}