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

int N, W;
double M;

double edge[1005][1005];

vector<double> Dijkstra(int start)
{
    vector<double> dist(N + 1, -1);
    priority_queue<pair<double, int>> pq; // first : dist , second : vertex_pos

    dist[start] = 0;
    pq.push(make_pair(-dist[start], start)); // Min-Heap처럼 사용하기 위해 앞의 거리 인자에 -값을 곱해줌.
    while (!pq.empty())
    {
        int here = pq.top().second;
        double heredist = -pq.top().first;

        pq.pop();
        if (heredist > dist[here])
            continue;
        for (int there = 1; there <= N; there++)
        {
            if (here == there)
                continue;
            double nextdist = heredist + edge[here][there];
            if (dist[there] == -1 || dist[there] > nextdist)
            { // 최단 거리 갱신
                dist[there] = nextdist;
                pq.push(make_pair(-nextdist, there));
            }
        }
    }
    return dist;
}

int main()
{
    // 정점의 개수, 간선의 개수, 시작 정점
    scanf("%d %d\n %lf", &N, &W, &M);

    map<int, ii64> mp;

    for (int i = 1; i <= N; i++)
    {
        i64 x, y;
        scanf("%lld %lld", &x, &y);

        // (0, 0)을 (200000, 200000)으로 옮겨서 음수를 처리
        mp[i] = make_pair(x + 200000, y + 200000);
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
            {
                edge[i][j] = MAXV;
                continue;
            }
            i64 x1 = mp[i].first;
            i64 y1 = mp[i].second;

            i64 x2 = mp[j].first;
            i64 y2 = mp[j].second;

            // 거리 계산
            double dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
            if (M < dist)
            {
                edge[i][j] = MAXV;
                continue;
            }

            // printf("%d %d %lf %lf\n", i, j, M, dist);
            edge[i][j] = dist;
            edge[j][i] = dist;
        }
    }

    for (int i = 1; i <= W; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        i64 x1 = mp[a].first;
        i64 y1 = mp[a].second;
        i64 x2 = mp[b].first;
        i64 y2 = mp[b].second;

        // 추가로 건설할 필요가 없다 (비용 0)
        edge[a][b] = 0;
        edge[b][a] = 0;
    }

    vector<double> dist = Dijkstra(1);
    printf("%.0lf", trunc(dist[N] * 1000.0));
    return 0;
}
