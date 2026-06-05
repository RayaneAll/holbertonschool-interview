#include <stdio.h>
#include "search_algos.h"

static int binary_search(int *array, int left, int right, int value);

int advanced_binary(int *array, size_t size, int value)
{
    if (array == NULL || size == 0)
        return (-1);

    return (binary_search(array, 0, (int)size - 1, value));
}

static int binary_search(int *array, int left, int right, int value)
{
    int mid, i;

    if (left > right)
        return (-1);

    printf("Searching in array: ");
    for (i = left; i <= right; i++)
    {
        printf("%d", array[i]);
        if (i < right)
            printf(", ");
    }
    printf("\n");

    mid = left + (right - left) / 2;
    if (array[mid] == value)
    {
        int idx = binary_search(array, left, mid - 1, value);

        if (idx != -1)
            return (idx);
        return (mid);
    }
    if (array[mid] < value)
        return (binary_search(array, mid + 1, right, value));
    return (binary_search(array, left, mid - 1, value));
}
