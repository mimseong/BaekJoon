#include <stdio.h>
#include <stdlib.h>

void read_data(int** input_list, int** find_list, int* input_size, int* find_size);
void selection_sort(int * list, int size);
int binary_search(int left, int right, int findN, int *list);
void swap(int *a, int *b);
int* Malloc(int size);

int main()
{
    int* input_list;
    int* find_list;
    int input_size, find_size, i, j;
    int result;
    
    read_data(&input_list, &find_list, &input_size, &find_size);
    
    selection_sort(input_list, input_size);
    
    for(i = 0; i < find_size; i++){
        result = binary_search(0, input_size - 1, find_list[i], input_list);
        printf("%d\n", result);
    }
    
    return 0;
}

void read_data(int** input_list, int** find_list, int* input_size, int* find_size){
    int i;
    int* input;
    int* find;
    
    scanf("%d ", input_size);
    input = Malloc(*input_size);
    
    for(i = 0; i < *input_size; i++)
        scanf("%d ", &input[i]);
    
    
    scanf("%d ", find_size);
    find = Malloc(*find_size);   
    
    for(i = 0; i < *find_size; i++)
    scanf("%d ", &find[i]);
    
    *input_list = input;
    *find_list = find;
}

int* Malloc(int size){
    return (int*)malloc(size * sizeof(int));
}

int binary_search(int left, int right, int findN, int *list){
    int middle = (left + right) / 2;
    
    if(right < left)
        return 0;
    
    if(findN < list[middle])
        right = middle - 1;
    else if (findN > list[middle])
        left = middle + 1;
    else
        return 1;
        
    binary_search(left, right, findN, list);
    
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int * list, int n){
    int i, j;
    int min;
    
    for(i = 0; i < n - 1; i++){
        min = i;
        for(j = i + 1; j < n; j++){
            if(list[min] > list[j]){
                min = j;
            }
        }
        swap(&list[min], &list[i]);
    }
}