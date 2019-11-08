#include <iostream>

int main()
{
    int n, max = 1, i = 1;
    scanf("%d", &n);

    for (; max < n; i++)
        max += i * 6;

    printf("%d\n", i);
    return 0;
}