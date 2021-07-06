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

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

int yi[10] = {0, -1, 0, 1, -1, 0, 1, -1, 0, 1};
int xi[10] = {0, 1, 1, 1, 0, 0, 0, -1, -1, -1};
int n, m;

void printV(vector<string> &v) {
    for (int i = 0; i < n; i++)
        cout << v[i] << "\n";
}

void dotV(vector<string> &v) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            v[i][j] = '.';
}

int main() {
    scanf("%d %d", &n, &m);
    
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    string s;
    cin >> s;
    
    ii jong;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 'I') {
                jong.xx = i;
                jong.yy = j;
            }
        }
    }
    
    // cout << jong.xx << " " << jong.yy << endl;
    
    int watch = 0;
    for (; watch < s.size(); watch++) {
        // printf("-----watch%d-----\n", watch);
        
        vector<string> newV = v;
        dotV(newV);
        
        int nxx = jong.xx + xi[s[watch] - '0'];
        int nyy = jong.yy + yi[s[watch] - '0'];
        
        // printf("next jong : %d %d\n", nxx, nyy);
        if (v[nxx][nyy] == 'R')
            break;
        
        newV[nxx][nyy] = 'I';
        jong.xx = nxx;
        jong.yy = nyy;
        
        // printf("next jong : %d %d\n", jong.xx, jong.yy);
        
        bool isEnd = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] != 'R')
                    continue;

                int len = 10000000;
                ii next;
                for (int k = 1; k <= 9; k++) {
                    int nx = i + xi[k];
                    int ny = j + yi[k];
                    
                    if (nx < 0 || n <= nx)
                        continue;
                    if (ny < 0 || m <= ny)
                        continue;
                    
                    if (abs(nx - jong.xx) + abs(ny - jong.yy) < len) {
                        len = abs(nx - jong.xx) + abs(ny - jong.yy);
                        next.xx = nx;
                        next.yy = ny;
                    }
                }
                
                // printf("next adu : %d %d\n", next.xx, next.yy);
                
                if (newV[next.xx][next.yy] == 'I') {
                    isEnd = true;
                    break;
                }
                if (newV[next.xx][next.yy] == 'R' || newV[next.xx][next.yy] == 'X') {
                    newV[next.xx][next.yy] = 'X';
                }
                else {
                    newV[next.xx][next.yy] = 'R';
                }
            }
        }
        
        if (isEnd)
            break;
            
        
        for (int k = 0; k < n; k++) {
            for (int h = 0; h < m; h++) {
                if (newV[k][h] == 'X')
                    newV[k][h] = '.';
            }
        }
        v = newV;
        
        // printV(v);
    }
    
    
    if (watch == s.size()) {
        // cout << "------------" << endl;
        printV(v);
        return 0;
    }
    
    printf("kraj %d\n", watch + 1);
    
    return 0;
}