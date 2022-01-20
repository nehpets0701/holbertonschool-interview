#include "sort.h"

/**
 * merge - merge two arrays
 * @left: left array
 * @nLeft: number of ints in left array
 * @right: right array
 * @nRight: number of ints in right array
 * @tmp: temp array
 */
void merge(int *left, size_t nLeft, int *right, size_t nRight, int *tmp)
{
	size_t i = 0, j = 0;

	while (i + j < nLeft + nRight)
	{
		if (i >= nLeft)
		{
			tmp[i + j] = right[j];
			j++;
		}
		else if (j >= nRight)
		{
			tmp[i + j] = left[i];
			i++;
		}
		else
		{
			if (left[i] <= right[j])
			{
				tmp[i + j] = left[i];
				i++;
			}
			else
			{
				tmp[i + j] = right[j];
				j++;
			}
		}
	}

	for (i = 0; i < nLeft + nRight; i++)
		left[i] = tmp[i];
}

/**
 * split - split for merge sort
 * @array: input
 * @size: size
 * @tmp: temp array
 */
void split(int *array, size_t size, int *tmp)
{
	size_t middle;

	if (array == NULL || size < 2)
		return;

	middle = size / 2;

	split(array, middle, tmp);
	split(array + middle, size - middle, tmp);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, middle);
	printf("[right]: ");
	print_array(array + middle, size - middle);

	merge(array, middle, array + middle, size - middle, tmp);

	printf("[Done]: ");
	print_array(array, size);
}


/**
*merge_sort-merge sort
*@array:input
*@size:size
*/
void merge_sort(int *array, size_t size)
{
	int *new;

	if (array == NULL || size < 2)
		return;

	new = malloc(sizeof(int) * size);
	if (new == NULL)
		exit(EXIT_FAILURE);

	split(array, size, new);

	free(new);
}
