#include "sort.h"

/**
 * radix_sort-radix sort
 * @array:input
 * @size:size
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int i, max, place, count[10], *final;

	if (array == NULL || size < 2)
		return;

	max = array[0];

	for (i = 1; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];

	for (place = 1; max / place > 0; place *= 10)
	{
		final = malloc(sizeof(int) * size);

		for (i = 0; i < 10; i++)
			count[i] = 0;

		for (i = 0; i < (int)size; i++)
			count[(array[i] / place) % 10]++;
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];
		for (i = (int)size - 1; i >= 0; i--)
		{
			final[count[(array[i] / place) % 10] - 1] = array[i];
			count[(array[i] / place) % 10]--;
		}
		for (i = 0; i < (int)size; i++)
			array[i] = final[i];

		free(final);
		print_array(array, size);
	}
}
