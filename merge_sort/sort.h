#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void print_array(const int*, size_t);
void merge_sort(int*, size_t);
void merge(int*, int*, size_t, size_t, size_t, size_t);
void merge_sort_recursive(int*, int*, size_t, size_t);
void copy_array(int*, int*, size_t, size_t);
void print_work_array(const int*, size_t, size_t);

#endif /* SORT_H */
