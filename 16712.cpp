#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <bitset>
#include <stdio.h>
#include <math.h>
#include <sstream>
#include <cassert>
#include <climits>
#include <tuple>

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()
#define MAXV 987654321
#define FOR(i, n) for (int i = 0; i < (n); ++i)

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);

  // 참가자들의 정보 실력과 초기 위치를 저장
  vector<ii> participants(n);
  FOR(i, n)
  {
    int a;
    scanf("%d", &a);
    participants[i] = {a, i};
  }

  // 각 대회의 탈락 순위를 저장
  vector<int> v(n - m + 1);
  FOR(i, n - m + 1)
  {
    scanf("%d", &v[i]);
  }

  // 현재 대회에 참가하는 M명의 참가자들을 관리
  vector<ii> current(m);
  FOR(i, m)
  {
    current[i] = participants[i];
  }

  // 각 대회 진행
  FOR(i, n - m + 1)
  {
    // 현재 참가자들을 실력순으로 정렬 (실력이 같으면 초기 위치순)
    sort(all(current), [](const ii &a, const ii &b)
         {
      if (a.xx != b.xx) return a.xx < b.xx;
      return a.yy < b.yy; });

    // Vi등을 한 사람 제거
    current.erase(current.begin() + v[i] - 1);

    // 새로운 참가자 추가
    if (i < n - m)
    {
      current.push_back(participants[m + i]);
    }
  }

  // 남은 참가자들의 실력만 추출하여 정렬
  vector<int> result;
  for (const auto &p : current)
  {
    result.push_back(p.xx);
  }
  sort(all(result));

  // 결과 출력
  for (int x : result)
  {
    printf("%d ", x);
  }
  printf("\n");

  return 0;
}
