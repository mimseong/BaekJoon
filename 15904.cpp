#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;
    getline(cin, a);
    int state = 0;
    
    for(int i = 0; i < a.length(); i++){
        if(a[i] == 'U' && state == 0)
            state = 1;
        else if(a[i] == 'C' && state == 1)
            state = 2;
        else if(a[i] == 'U' && state == 1) 
            state = 1;
        else if(a[i] == 'P' && state == 2) 
            state = 3;
        else if(a[i] == 'C' && state == 3){
            state = 4;
            break;
        }
    }
    if(state == 4)
        printf("I love UCPC");
    else
        printf("I hate UCPC");
}