#include <iostream>

using namespace std;

void changeAtoB(char a, char b, string& str1, string& str2){
    for(int i = 0; i < str1.length(); i++){
        if(str1[i] == a)
            str1[i] = b;
    }
    for(int i = 0; i < str2.length(); i++){
        if(str2[i] == a)
            str2[i] = b;
    }
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    changeAtoB('6', '5', str1, str2);
    cout << stoi(str1.c_str()) + stoi(str2.c_str()) << " ";
    changeAtoB('5', '6', str1, str2);
    cout << stoi(str1.c_str()) + stoi(str2.c_str());
}