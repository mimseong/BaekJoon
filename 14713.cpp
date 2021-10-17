#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <bitset>
#include <stdio.h>
#include <math.h>
#include <sstream> 

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using si = pair<string, int>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

vector<string> split(string s, char c){
    stringstream ss(s); 
 
    string word;
    vector<string> result;
    while (getline(ss, word, c)) { 
        result.push_back(word);
    }
    
    return result;
}

void printVector(vector<string> &v) {
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    
    string s;
    getline(cin, s); //remove buffer
    vector<string> v[100];
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        
        v[i] = split(s, ' ');
        v[i].push_back("!");
    }
    
    getline(cin, s); // 마지막 문자열
    
    vector<string> search = split(s, ' ');
    vector<bool> check(search.size());
    
    for (int i = 0; i < n; i++) {
        int k = 0;
        for (int j = 0; j < search.size(); j++) {
            if (search[j] != v[i][k])
                continue;
            
            check[j] = true;
            k++;
        }
        
        // 단어가 전부 사용되지 않은 경우
        if (k != v[i].size() - 1) {
            printf("Impossible\n");
            return 0;
        }
    }
    
    // 쓰이지 않은 단어가 있는 경우
    for (int i = 0; i < check.size(); i++) {
        if (check[i] == false) {
            printf("Impossible\n");
            return 0;
        }
    }
    
    printf("Possible\n");
    return 0;
}