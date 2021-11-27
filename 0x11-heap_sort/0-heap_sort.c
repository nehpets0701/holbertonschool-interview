#include "sort.h"

/**
 * heap_sort-heap sort array
 * @array:array to sort
 * @size:size of array
 */
void heap_sort(int *array, size_t size)
{
	int i, new;

	for (i = (int)size / 2 - 1; i >= 0; i--)
		makeHeap(array, (int)size, size, i);

	for (i = (int)size - 1; i > 0; i--)
	{
		new = array[i];
		array[i] = array[0];
		array[0] = new;
		print_array(array, size);

		makeHeap(array, i, size, 0);
	}
}

/**
 * makeHeap-make a heap from array
 * @array:input
 * @n:number of numbers
 * @size:size
 * @i:index
 */
void makeHeap(int *array, int n, size_t size, int i)
{
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int new;

	if (left < n && array[left] > array[max])
		max = left;

	if (right < n && array[right] > array[max])
		max = right;

	if (max != i)
	{
		new = array[max];
		array[max] = array[i];
		array[i] = new;
		print_array(array, size);

		makeHeap(array, n, size, max);
	}
}
