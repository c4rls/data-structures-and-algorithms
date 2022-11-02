#include <stdbool.h>

void selection_sort_int(int *arr, unsigned int arr_size, bool ascending);

void _selection_sort(
    void *arr,
    unsigned int obj_size,
    unsigned int arr_size,
    bool ascending,
    char (*cmp)(void *a, void *b)
);

#define selection_sort(type, arr, size, asc, func) _selection_sort((arr), (sizeof(type)), (size), (asc), (func))