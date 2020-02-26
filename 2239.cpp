#include <iostream>
#include <vector>

using namespace std;
vector <vector<int>> ans(9, vector <int> (9));
vector <vector<int>> map(9, vector <int> (9));

void    print_ans()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d", ans[i][j]);
        }
        printf("\n");
    }
}

bool    row_check(int i, int j)
{
    vector<int> tmp (9, 0);

    for (int k = 0; k < 9; k++)
    {
        tmp[ans[i][k] - 1]++;
    }
    for (int k = 0; k < 9; k++)
    {
        if (tmp[k] != 1)
            return (false);
    }
    return (true);
}

bool    col_check(int i, int j)
{
    cout << "col_index " << i << " " << j << endl;
    print_ans();
    printf("\n");
    vector<int> tmp (9, 0);

    for (int k = 0; k <= j; k++)
    {
        tmp[ans[k][j] - 1]++;
    }
    for (int k = 0; k <= j; k++)
    {
        if (tmp[k] != 1)
            return (false);
    }
    return (true);
}

bool    box_check(int i, int j)
{
    vector<int> tmp (9, 0);
    
    for (int k = i - 2; k < i; k++)
    {
        for (int m = j - 2; m < j; m++)
            tmp[ans[k][m] - 1]++;
    }
    for (int k = 0; k < 9; k++)
    {
        if (tmp[k] != 1)
            return (false);
    }
    return (true);
}

bool    check(int i, int j)
{
    if(!col_check(i, j))
        return (false);
    if (j == 8)
    {
        if (!row_check(i, j))
            return (false);
    }
    if (i % 3 == 2 && j % 3 == 2)
    {
        if(box_check(i, j))
            return (false);
    }
    return (true);
}

bool    sudoku(int i, int j)
{
    printf("%d %d\n", i, j);
    print_ans();
    printf("\n");
    if (i == 9)
        return (true);
    else
    {
        if (map[i][j] == 0)
        {
            for (int k = 1; k <= 9; )
            {
                ans[i][j] = k++;
                if (!check(i, j))
                    continue;
                int result;
                if (j == 8)
                    result = sudoku(i + 1, 0);
                else
                    result = sudoku(i, j + 1);
                if (result)
                    return (true);
            }
        }
        else
        {
            int result;
            if (j == 8)
                result = sudoku(i + 1, 0);
            else
                result = sudoku(i, j + 1);
            if (result)
                return (true);
        }
    }
    return (false);
}

int     main()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%1d ", &ans[i][j]);
            map[i][j] = ans[i][j];
        }
    }
    print_ans();
    printf("\n");
    if (sudoku(0, 0))
        print_ans();
    else
        printf("no ans\n");
    return (0);
}