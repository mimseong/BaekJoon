#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define MIN -2147483648
#define MAX 2147483647
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    
    for(int i = 0; i < t; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        vector<int> va(a);
        vector<int> vb(b);
        
        
        for(int j = 0; j < a; j++)
            scanf("%d", &va[j]);
        for(int j = 0; j < b; j++)
            scanf("%d", &vb[j]);
        vb.push_back(MIN);
        vb.push_back(MAX);
        
        sort(vb.begin(), vb.end(), greater<int>());
        int sum = 0;
        for(int j = 0; j < a; j++){
            int l = 0;
            int h = vb.size() - 1;
            
            while(true){
                if(l == h - 1){
                    if(h != vb.size() - 1)
                        sum += vb.size() - 1 - h;
                    break;
                }
                int mid = (l+h)/2;
                
                if(vb[mid] >= va[j])
                    l = mid;
                else
                    h = mid;

            }
        }
        printf("%d\n", sum);
    }
    
    return 0;
}