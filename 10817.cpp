#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    pq.push(a);
    pq.push(b);
    pq.push(c);
    pq.pop();
    printf("%d", pq.top());
}