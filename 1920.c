#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void read_data(int** input_list, int** find_list, int* input_size, int* find_size);
int binary_search(int left, int right, int findN, int *list);
void swap(int *a, int *b);
int* Malloc(int size);
void quick_sort(int list[], int low, int high);
int partition(int list[], int low, int high);
int rand_partition(int list[], int low, int high);

int main()
{
    int* input_list;
    int* find_list;
    int input_size, find_size, i, j;
    int result;
    
    read_data(&input_list, &find_list, &input_size, &find_size);
    
    quick_sort(input_list, 0, input_size - 1);
    
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

int rand_partition(int list[], int low, int high){
    int i;
    srand(time(NULL));
    i = low + rand() % (high - low);
    swap(&list[low], &list[i]);
    return partition(list, low, high);
}

void quick_sort(int list[], int low, int high){
    if (high > low){
        int pivotpoint = rand_partition(list, low, high);
        quick_sort(list, low, pivotpoint - 1);
        quick_sort(list, pivotpoint + 1, high);
    }  
}

int partition(int list[], int low, int high){
    int i, j = low;
    int pivotitem = list[low];

    for (i = low + 1; i <= high; i++){
        if (list[i] < pivotitem) {
            j++;
            swap(&list[i], &list[j]);
        }
    }
    swap(&list[low], &list[j]);
    return j;
}

void swap(int* a, int*b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}