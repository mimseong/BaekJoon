#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    string str = to_string(a*b*c);
    int result[10] = {0, };
    
    for(int i = 0; i < str.length(); i++)
        result[str[i] - '0']++;
    
    for(int i = 0; i < 10; i++)
        printf("%d\n", result[i]);
    
    return 0;
}