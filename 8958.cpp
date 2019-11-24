#include <iostream>
#include <cstring>

int main() {
    int n;
    char str[81];
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        int sum = 0, count = 0;
        scanf("%s", str);
        
        for(int j = 0; j < strlen(str); j++){
            if(str[j] == 'O')
                sum += ++count;
            else
                count = 0;
        }
        printf("%d\n", sum);
    }
    
    return 0;
}