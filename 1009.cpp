#include <iostream>

int arr[10][4]={{0,0,0,0},{1,1,1,1},{6,2,4,8},
                {1,3,9,7},{6,4,6,4},{5,5,5,5},
                {6,6,6,6},{1,7,9,3},{6,8,4,2},{1,9,1,9}};

int main() {
    int t, a, b;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d %d", &a, &b);
        a %= 10;
        b %= 4;
        if(arr[a][b] == 0)
            printf("1");
        printf("%d\n", arr[a][b]);
    }
}