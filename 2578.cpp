#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector <int> num(25);
    vector <bool> check(26);
    
    for(int i = 0; i < 25; i++){
        int input;
        scanf("%d", &input);
        num[i] = input; check[i] = false;
    }
    check[25] = false;
    
    for(int i = 0; i < 11; i++){
        int input;
        scanf("%d", &input);
        check[input] = true;
    }
    
    for(int k = 12; k <= 25; k++){
        int input;
        scanf("%d", &input);
        check[input] = true;
        
        int bingo = 0;
        for(int i = 0; i < 5; i++){
            if(check[num[5*i+0]] == true && check[num[5*i+1]] == true && check[num[5*i+2]] == true 
            && check[num[5*i+3]] == true && check[num[5*i+4]] == true)
                bingo++;
            if(check[num[0+i]] == true && check[num[5+i]] == true && check[num[10+i]] == true 
            && check[num[15+i]] == true && check[num[20+i]] == true)
                bingo++; 
        }
        if(check[num[0]] == true && check[num[6]] == true && check[num[12]] == true 
            && check[num[18]] == true && check[num[24]] == true)
                bingo++;
        if(check[num[4]] == true && check[num[8]] == true && check[num[12]] == true 
            && check[num[16]] == true && check[num[20]] == true)
                bingo++;
        if(bingo >= 3){
            printf("%d", k);
            break;
        }
    }
    return 0;
}