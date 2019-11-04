#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, i;
    
    scanf("%d", &n);
    vector<int> arr(n);
    
    for(i = 0; i < n; i++)
          scanf("%d", &arr[i]);
    
    sort(arr.begin(), arr.end());
    cout << arr[0] * arr[n-1];
}