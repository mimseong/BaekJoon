#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    
    for(int i = 0; i < t; i++){
        int n;
        string s;
        cin >> n >> s;
        
        for(int j = 0; j < s.size(); j++){
            for(int k = 0; k < n; k++){
                cout << s[j];
            }
        }
        cout << endl;
    }
    
    return 0;
}