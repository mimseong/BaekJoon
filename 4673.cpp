#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;

    for(int i = 0; i <= 10000; i++)
        v.push_back(1);

    for(int i = 1; i <= 10000; i++){
        if(v[i] == -1)
            continue;
        int n = i;

        while(n <= 10000) {
            int sum = 0, tmp = n;

            while(tmp != 0){
                sum += tmp%10;
                tmp /= 10;
            }

            n = n + sum;
            v[n] = -1;
        }
    }
    for(int i = 1; i <= 10000; i++){
        if(v[i] != -1)
            printf("%d\n", i);
    }
}