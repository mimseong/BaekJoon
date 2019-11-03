#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int arr[1000000];
    
    scanf("%d", &n);
    
   for(int i = 0; i < n; i++){
       scanf("%d", &arr[i]);
   }
   sort(arr, arr + n);
   printf("%d %d", arr[0], arr[n-1]);
}