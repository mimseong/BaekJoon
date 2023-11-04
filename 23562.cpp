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
#include<cassert>
#include <climits>
#include <tuple>

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()
#define MAXV 987654321
#define FOR(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

int n, m, a, b;
vector<string> mapv(25);

bool isDigeud(int x, int y, int startX, int startY, int size) {
    bool result = false;

    if (startX <= x && x < startX+size*3 && startY <= y && y < startY+size)
        result = true;
    if (startX <= x && x < startX+size && startY+size <= y && y < startY+size*3)
        result = true;
    if (startX+size*2 <= x && x < startX+size*3 && startY+size <= y && y < startY+size*3)
        result = true;
    return result;
}

// 디귿이 정해져있을 때 전체 순회하면서 가격 계산
int calcPrice(int startX, int startY, int size) {
    int price = 0;

    FOR(x, n) {
        FOR (y, m) {
            // 디귿인데 흰색인 경우
            if (isDigeud(x, y, startX, startY, size) && mapv[x][y] == '.')
                price += a;
            // 디귿이 아닌데 검은색인 경우
            else if (!isDigeud(x, y, startX, startY, size) && mapv[x][y] == '#')
                price += b;
        }
    }

    return price;
}

int main() {
	cin >> n >> m >> a >> b;

	FOR(i, n) {
	    cin >> mapv[i];
	}

	int price = MAXV;
	for (int size = 1; size * 3 <= min(n, m); size++) {
	   // printf("size: %d\n", size);
	    for (int startX = 0; startX + size*3 <= n; startX++) {
	        for (int startY = 0; startY + size*3 <= m; startY++) {
	           // printf("x: %d,y: %d\n", startX, startY);
	           price = min(calcPrice(startX, startY, size), price);
	        }
	    }
	}

	cout << price << "\n";

	return 0;
}
