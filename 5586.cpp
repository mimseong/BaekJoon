#include <iostream>

using namespace std;

int main() {
    int jstate = 1, istate = 1;
    int jcount = 0, icount = 0;
    string str;
    cin >> str;
    
    for(int i = 0; i < str.length(); i++){
        //JOI
        if(str[i] == 'J' && jstate == 1){
            jstate = 2;
        }
        else if(jstate == 2){
            if(str[i] == 'O')
                jstate = 3;
            else if(str[i] != 'J')
                jstate = 1;
        }
        else if(jstate == 3){
            if(str[i] == 'I')
                jcount++;
            jstate = 1;
        }
    //IOI
        if(str[i] == 'I' && istate == 1)
            istate = 2;
        else if(istate == 2){
            if(str[i] == 'O')
                istate = 3;
            else if(str[i] != 'I')
                istate = 1;
        }
        else if(istate == 3){
            if(str[i] == 'I'){
                icount++;
                istate = 2;
            }
            else istate = 1;
        }
    }
    printf("%d\n%d", jcount, icount);
}