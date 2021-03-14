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

int check[2005][2005];

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

int main() {
    int d1, d2;
    scanf("%d %d", &d1, &d2);
    
    int sum = 0;
    for (int i = d1; i <= d2; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            int t = gcd(i, j);
            //printf("%d ", t);
            if (check[j / t][i / t] == 0)
                sum++;
            check[j / t][i / t] = 1;
            // printf("\n");
        }
    }
    
    printf("%d\n", sum);
    
    
    return 0;
}