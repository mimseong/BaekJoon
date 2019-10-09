#include <iostream>

int main() {
    char c;
    bool isOdd = true;
    int count = 0;
    
    for(int i = 1; i <= 64; i++){
        scanf("%c", &c);
        if(isOdd){
            if(i%2 == 1 && c == 'F')
                count++;
        }
        else{
            if(i%2 == 0 && c == 'F')
                count++;
        }
        if(i%8 == 0){
            scanf("%c", &c);    //remove buffer
            isOdd = !(isOdd);
        }
        
    }
    printf("%d", count);
    
    return 0;
}