#include <iostream>
#include <string>

using namespace std;

int main() {
    string num_str;
    cin >> num_str;

    string octal_number[8];
    string first_octal_number[8];
    
    octal_number[0] = "000";
    octal_number[1] = "001";
    octal_number[2] = "010";
    octal_number[3] = "011";
    octal_number[4] = "100";
    octal_number[5] = "101";
    octal_number[6] = "110";
    octal_number[7] = "111";
    
    first_octal_number[0] = "0";
    first_octal_number[1] = "1";
    first_octal_number[2] = "10";
    first_octal_number[3] = "11";
    first_octal_number[4] = "100";
    first_octal_number[5] = "101";
    first_octal_number[6] = "110";
    first_octal_number[7] = "111";

    int length = num_str.length();
    int number = atoi(num_str.c_str());

    for(int i = length - 1; i >= 0; i--){
        if(i == length - 1)
            cout << first_octal_number[num_str[i] - '0'];
        cout << octal_number[num_str[i] - '0'];
    }
}