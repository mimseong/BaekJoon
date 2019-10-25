#include <iostream>
#include <string>

using namespace std;

int main() {
    string num_str;
    cin >> num_str;

    string octal_number[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};
    string first_octal_number[8] = {"0", "1", "10", "11", "100", "101", "110", "111"};
    
    int length = num_str.length();

    for(int i = 0; i < length; i++){
        if(i == 0)
            cout << first_octal_number[num_str[i] - '0'];
        else cout << octal_number[num_str[i] - '0'];
    }
}