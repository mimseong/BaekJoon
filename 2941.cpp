#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using i64 = long long;

int find_s(string s, string c)
{
    int count = 0;
    int i = -1;
    
    while ((i = s.find(c, i+1)) != -1)
        count++;
    
    return count;
}

int main(){
    string s;
    cin >> s;

    int sum = 0;
    sum += find_s(s, "c="); 
    sum += find_s(s, "c-"); 
    sum += find_s(s, "d-"); 
    sum += find_s(s, "lj"); 
    sum += find_s(s, "nj"); 
    sum += find_s(s, "s="); 
    int z = find_s(s, "z="); 
    int dz = find_s(s, "dz="); 
    
    z = z - dz;
    sum += z;
    
    cout << s.size() - sum - dz*2;


    return 0;
}