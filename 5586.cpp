#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s;
  cin >> s;

  int ioi = 0, joi = 0;

  for (int i = 0; i < s.size() - 2; i++)
  {
    string sub = s.substr(i, 3);

    if (sub == "JOI")
      joi++;
    if (sub == "IOI")
      ioi++;
  }
  
  printf("%d\n%d", joi, ioi);

  return 0;
}