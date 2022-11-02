#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap_arr_int(int *arr, unsigned int i, unsigned int j) {
    int temp;

    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void swap_arr(
    void *arr,
    unsigned int obj_size,
    unsigned int i,
    unsigned int j
) {
    void *temp;

    temp = malloc(obj_size);

    memcpy(temp, arr + i * obj_size, obj_size);
    memcpy(arr + i * obj_size, arr + j * obj_size, obj_size);
    memcpy(arr + j * obj_size, temp, obj_size);

    free(temp);
}

void print_arr_int(int *arr, unsigned int arr_size) {
    while (arr_size-- > 0)
        printf("%d ", *arr++);
}