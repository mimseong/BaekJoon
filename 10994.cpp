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


int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i <= (4*n - 3)/2; i++)
    {
        for (int j = 0; j < (i+1)/2; j++)
            printf("* ");
        
        if(i%2 == 0)
        {
            for (int j = 0; j < (4*n-3)-2*i; j++)
                printf("*");
        }
        else
        {
            for (int j = 0; j < (4*n-3)-2*(i+1); j++)
                printf(" ");
        }
        
        for (int j = 0; j < (i+1)/2; j++)
            printf(" *");
        printf("\n");
    }
    for (int i = (4*n - 3)/2 - 1; i >= 0 ; i--)
    {
        for (int j = 0; j < (i+1)/2; j++)
            printf("* ");
        
        if(i%2 == 0)
        {
            for (int j = 0; j < (4*n-3)-2*i; j++)
                printf("*");
        }
        else
        {
            for (int j = 0; j < (4*n-3)-2*(i+1); j++)
                printf(" ");
        }
        
        for (int j = 0; j < (i+1)/2; j++)
            printf(" *");
        printf("\n");
    }
    
    return 0;
}