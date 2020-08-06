#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()
 
using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int v[105];
int w[105];
int arr[105][100005];

def KS(n, c)
{
	if (arr[n][c] != 0)
		return arr[n][c];
	if (n == 0 || c == 0)
		result = 0;
	else if ( w[n] > c)
		result = KS(n-1, c);
	else
	{
		int tmp1 = KS(n-1, c);
		int tmp2 = v[n] + KS(n-1, c - w[n]);
		result = max(tmp1, tmp2);
	}
	arr[n][c] = result;
	return result;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i++)
    	scanf("%d %d", &w[i], &v[i]);
    
    
    return 0;
}