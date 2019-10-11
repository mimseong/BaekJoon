#include <iostream>
#include <algorithm>
using namespace std;

int Rev(string& str){
    reverse(str.begin(), str.end());
    return atoi(str.c_str());
}

int main() {
    string x, y;
    cin >> x >> y;
    
    string result = to_string(Rev(x) + Rev(y));
    cout << Rev(result);
    
    return 0;
}