#include <iostream>
#include <string>

using namespace std;

int main() {
    int words = 0;
    string str;
    
    while(cin >> str)
        words++;
        
    printf("%d", words);
        
    return 0;
}