#include <iostream>
#include <string>

using namespace std;

int main()
{
    int count = 0;
    
    for(int i = 0; i < 8; i++){
        string s;
        cin >> s;
        
        for(int j = 0; j < 8; j++){
            if(s[j] == 'F' && (i+j) % 2 == 0)
                count++;
        }
    }
    
    printf("%d", count);
    return 0;
}