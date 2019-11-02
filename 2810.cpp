#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    string a;
    cin >> a;
    int count = 0;
    for(int i = 0; i < a.length(); i++){
        if(a[i] == 'L')
            i++;
        count++;
    }
    
    printf("%d", min(++count, n));
    return 0;
}