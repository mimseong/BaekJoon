#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<pair <int, char>> v;
    char c;
    
    for(int i = 0; i < 26; i++)
        v.push_back(pair <int, char> (0, i+'A'));

    while(cin >> c){
        if('a' <= c && c <= 'z')
            c -= 32;
        v[c-'A'].first++;
    }
    sort(v.begin(), v.end());

    
    if(v[25].first == v[24].first)
        printf("?");
    else
        printf("%c", v[25].second);
    
    
    return 0;
}