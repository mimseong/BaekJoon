#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    bool isJava = true, isCpp = true;
    if (s[0] < 97 || 122 < s[0]){
        isJava = false; isCpp = false;
    }
    for(int i = 1; i < s.length(); i++){
        if(s[i] == '_'){
            if(s[i-1] == '_' || i == s.length()-1)
                isCpp = false;
            isJava = false;
        }
        else if (65 <= s[i] && s[i] <= 90){
            isCpp = false;
        }
        else if (s[i] < 97 || 122 < s[i]){
            isJava = false; isCpp = false;
        }
    }
    
    string r = "";
    if(!isJava && !isCpp){
        printf("Error!");
    }
    else if(isJava){
        for(int i = 0; i < s.length(); i++){
            if (65 <= s[i] && s[i] <= 90){
                r += "_"; r += s[i]+32;
            }
            else
                r += s[i];
        }
    }
    else if(isCpp){
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '_'){
                r += s[i+1]-32;
                i++;
            }
            else
                r += s[i];
        }
    }
    cout << r;
    return 0;
}