#include <iostream>

using namespace std;
using i64 = long long;

int main() {
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    
    a.append(b);
    c.append(d);
    
    i64 sum1 = stoll(a);
    i64 sum2 = stoll(c);
    
    cout << sum1+sum2;
}