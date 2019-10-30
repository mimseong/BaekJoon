#include <iostream>

using namespace std;
using ii = pair<int, int>;

int main() {
    ii special = {2, 18};
    ii date;
    scanf("%d %d", &date.first, &date.second);
    
    if(date < special)
        printf("Before");
    else if(date > special)
        printf("After");
    else
        printf("Special");
        
    return 0;
}