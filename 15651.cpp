#include <iostream>
#include <vector>

using namespace std;

void    print_vector(int m, vector<int> v)
{
    for (int i = 0; i < m; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}


void    find_sequence(int index, int n, int m, vector<int> v)
{
    if (index == m)
        print_vector(m, v);
    else
    {
        for (int i = 1; i <= n; )
        {
            v[index] = i++;
            find_sequence(index + 1, n, m, v);
        }
    }
}

int     main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> v(m, 0);
    
    find_sequence(0, n, m, v);
}