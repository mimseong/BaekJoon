#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
    cout << s;
    
    return 0;
}