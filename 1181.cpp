#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(string a, string b){
    if(a.length() == b.length())
        return a < b;
    else
        return a.length() < b.length();
}

int main() {
    int n;
    scanf("%d", &n);
    vector <string> v(n);
    
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end(), compare);
    for(int i = 0; i < n; i++){
        if(v[i] == v[i+1])
            continue;
        cout << v[i] << endl;
    }
}