#include <iostream>
#include <string>
#include <bits/stdc++.h> 
using namespace std;

int main() {
    string s1, s2, result;
    cin >> s1 >> s2;
    
    int start1 = s1.length() - 1;
    int start2 = s2.length() - 1;
    for(int i = 0; i < s1.length(); i++){
        if(s1[i] == '1'){
            start1 = i;
            break;
        }
    }
    for(int i = 0; i < s2.length(); i++){
        if(s2[i] == '1'){
            start2 = i;
            break;
        }
    }
    
    int end1 = s1.length() - 1;
    int end2 = s2.length() - 1;
    int carry = 0;
    while(true) {
        int tmp = (s1[end1]-'0') + (s2[end2]-'0') + carry;
        carry = tmp/2;
        result += (tmp%2) + '0';
        
        end1--; end2--;
        
        if(end1+1 == start1)
            break;
        if(end2+1 == start2)
            break;
            
        
    }
    
    for(; (start1 != end1+1); end1--){
        int tmp = (s1[end1]-'0') + carry;
        carry = tmp/2;
        result += (tmp%2) + '0';
    }
    for(; (start2 != end2+1); end2--){
        int tmp = (s2[end2]-'0') + carry;
        carry = tmp/2;
        result += (tmp%2) + '0';
    }
    
    if(carry == 1){
        result += (carry + '0');
    }
        
    reverse(result.begin(), result.end());
        
    cout << result;
    
    return 0;
}