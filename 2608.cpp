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
#include <cmath>

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()

using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int     to_num(string str)
{
    int sum = 0;

    str += " ";
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'I')
        {
            if (str[i + 1] == 'V')
            {
                sum += 4;
                i++;
                continue;
            }
            else if (str[i + 1] == 'X')
            {
                sum += 9;
                i++;
                continue;
            }
        }
        else if (str[i] == 'X')
        {
            if (str[i + 1] == 'L')
            {
                sum += 40;
                i++;
                continue;
            }
            else if (str[i + 1] == 'C')
            {
                sum += 90;
                i++;
                continue;
            }
        }
        else if (str[i] == 'C')
        {
            if (str[i + 1] == 'D')
            {
                sum += 400;
                i++;
                continue;
            }
            else if (str[i + 1] == 'M')
            {
                sum += 900;
                i++;
                continue;
            }
        }

        if (str[i] == 'I')
            sum += 1;
        else if (str[i] == 'V')
            sum += 5;
        else if (str[i] == 'X')
            sum += 10;
        else if (str[i] == 'L')
            sum += 50;
        else if (str[i] == 'C')
            sum += 100;
        else if (str[i] == 'D')
            sum += 500;
        else if (str[i] == 'M')
            sum += 1000;
    }

    return sum;
}

int     main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int sum = to_num(s1) + to_num(s2);
    printf("%d\n", sum);

    while (sum > 0) 
    { 
        if (sum >= 1000) 
            cout << "M", sum -= 1000; 
        else if (sum >= 900) 
            cout << "CM", sum -= 900; 
        else if (sum >= 500) 
            cout << "D", sum -= 500; 
        else if (sum >= 400) 
            cout << "CD", sum -= 400; 
        else if (sum >= 100) 
            cout << "C", sum -= 100; 
        else if (sum >= 90) 
            cout << "XC", sum -= 90; 
        else if (sum >= 50) 
            cout << "L", sum -= 50; 
        else if (sum >= 40) 
            cout << "XL", sum -= 40; 
        else if (sum >= 10) 
            cout << "X", sum -= 10; 
        else if (sum >= 9) 
            cout << "IX", sum -= 9; 
        else if (sum >= 5) 
            cout << "V", sum -= 5; 
        else if (sum >= 4) 
            cout << "IV", sum -= 4; 
        else 
            cout << "I", sum -= 1; 
    }


    return 0;
}