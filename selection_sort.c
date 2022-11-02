#include <stdbool.h>
#include "array_utilities.h"

void selection_sort_int(int *arr, unsigned int arr_size, bool ascending) {
    unsigned int temp;

    for (int i = 0; i < arr_size - 1; i++) {
        temp = i;

        for (int j = i + 1; j < arr_size; j++) {
            if (ascending) {
                if (arr[j] < arr[temp])
                    temp = j;
            } else {
                if (arr[j] > arr[temp])
                    temp = j;
            }
        }

        if (temp != i)
            swap_arr_int(arr, i, temp);
    }
}

void _selection_sort(
    void *arr,
    unsigned int obj_size,
    unsigned int arr_size,
    bool ascending,
    char (*cmp)(void *a, void *b)
) {
    unsigned int temp;
    int cmp_result;

    for (int i = 0; i < arr_size - 1; i++) {
        temp = i;

        for (int j = i + 1; j < arr_size; j++) {
            cmp_result = cmp(arr + j * obj_size, arr + temp * obj_size);

            if (ascending) {
                if (cmp_result < 0)
                    temp = j;
            } else {
                if (cmp_result > 0)
                    temp = j;
            }
        }

        if (temp != i)
            swap_arr(arr, obj_size, i, temp);
    }
}