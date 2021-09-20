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

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ss = pair<string, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;


int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    
    for (int i = 0; i < skill.size(); i++) {
        int type = skill[i][0];
        int r1 = skill[i][1] + 1;
        int c1 = skill[i][2] + 1;
        int r2 = skill[i][3] + 1;
        int c2 = skill[i][4] + 1;
        int degree = skill[i][5];
        
        board[r1][c1] += 1;
        board[r1][c2 + 1] += -1;
        board[r2 + 1][c1] += -1;
        board[r2 + 1][c2 + 1] += 1;
    }
    
    for (int i = 0; i < board.size(); i++) {
        for (int j = 1; j < board[0].size(); j++) {
            board[i][j] += board[i][j - 1];
        }
    }
    
    for (int j = 0; j < board[0].size(); j++) {
        for (int i = 1; i < board.size(); i++) {
            board[i][j] += board[i - 1][j];
        }
    }
    
    for (int i = 1; i < board.size() - 1; i++) {
        for (int j = 1; j < board[0].size() - 1; j++) {
            if (board[i][j] + t2[i][j] + board[i - 1][j - 1] <= 0)
                answer++;
        }
    }
    
    
    return 0;
}