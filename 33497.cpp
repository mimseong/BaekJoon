#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);

  vector<int> a(n);
  vector<int> b(n);
  vector<int> vacant(m);

  for (int i = 0; i < m; i++)
  {
    scanf("%d %d", &a[i], &b[i]);
  }

  int vacantCount = 0;
  for (int i = 0; i < m; i++)
  {
    vacant[i] = n - (a[i] + b[i]);

    if (vacant[i] < 0)
    {
      printf("NO\n");
      return 0;
    }

    vacantCount += vacant[i];
  }

  if (vacantCount < n)
  {
    printf("NO\n");
    return 0;
  }

  vector<vector<char>> ans(m, vector<char>(n));
  int vacantIdx = 0;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < vacant[i] && vacantIdx < n; j++, vacantIdx++)
    {
      ans[i][vacantIdx] = 'X';
    }
  }

  for (int i = 0; i < m; i++)
  {
    int idx = 0;

    for (int j = 0; j < a[i]; idx++)
    {
      if (ans[i][idx] == 'X')
      {
        continue;
      }
      ans[i][idx] = '+';
      j++;
    }
    for (int j = 0; j < b[i]; idx++)
    {
      if (ans[i][idx] == 'X')
      {
        continue;
      }
      ans[i][idx] = '-';
      j++;
    }

    for (; idx < n; idx++)
    {
      if (ans[i][idx] == 'X')
      {
        continue;
      }
      ans[i][idx] = '+';
    }
  }

  printf("YES\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      printf("%c", ans[j][i]);
    }
    printf("\n");
  }
}
