#ifndef SORT_H
#define SORT_H

#include <stdlib.h>

void heap_sort(int *array, size_t size);
void makeHeap(int *array, int n, size_t size, int i);
void print_array(const int *array, size_t size);

#endif
