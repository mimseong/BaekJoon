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
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

bitset<9> filp(bitset<9> a, bitset<9> b) {
    bitset<9> tmp1, tmp2;
    
    tmp1 = (~a) & b;
    tmp2 = (~b) & a;
    return tmp1 | tmp2;
}

void solve() {
    string bitString = "";
    for (int i = 0; i < 3; i++) {
        string input;
        cin >> input;
        
        for (int j = 0;  j < input.size(); j++) {
            if (input[j] == '.')
                bitString += "0";
            else
                bitString += "1";
        }
    }

    //bitmap 배열 만듬 - 더러워
    vector<string> bitStringVector = {"110100000", "111010000", "011001000", 
                                        "100110100", "010111010", "001011001", 
                                        "000100110", "000010111", "000001011"};
    vector<bitset<9>> bitV(9);
    for (int i = 0; i < bitStringVector.size(); i++) {
        for (int j = 0; j < bitStringVector[i].size(); j++) {
            bitV[i][8 - j] = bitStringVector[i][j] - '0';
        }
    }
    
    bitset<9> mapBit(bitString); // 이제 구해야 하는 조합
    
    int ans = 100;
    for (int i = 0; i < (1 << 9); i++) {
        bitset<9> calc;
        int count = 0;
        for (int j = 0; j < 9; j++) {
            if (!(i & (1 << j)))
                continue;
            count++;
            
            // j번째 비트맵을 뒤집는다
            calc = filp(calc, bitV[j]);
        }
        
        if (calc == mapBit)
            ans = min(ans, count);
    }

    cout << ans << "\n";
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        solve();
    }
    
    return 0;
}