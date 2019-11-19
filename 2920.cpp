#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector <int> ascending = {1, 2, 3, 4, 5, 6, 7, 8};
    vector <int> descending = {8, 7, 6, 5, 4, 3, 2, 1};
    int num;
    vector <int> input(8);
    
    for(int i = 0; i < 8; i++){
        scanf("%d", &input[i]);
    }
    
    if(ascending == input)
        printf("ascending");
    else if (descending == input)
        printf("descending");
    else
        printf("mixed");
        
    return 0;
}