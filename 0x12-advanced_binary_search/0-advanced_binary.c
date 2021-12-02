#include "search_algos.h"

/**
 * printArray-prints array
 * @array:input
 * @size:size
 */
void printArray(int *array, size_t size)
{
	size_t index;

	printf("Searching in array: ");
	for (index = 0; index < size; index++)
	{
		if (index == (size - 1))
			printf("%d\n", array[index]);
		else
			printf("%d, ", array[index]);
	}
}

/**
 * advanced_binary-binary search an array
 * @array:input
 * @size:size
 * @value:value to search for
 * Return: index of value if it is there
 */
int advanced_binary(int *array, size_t size, int value)
{
	int mid, right;

	if (array == NULL || size == 0)
		return (-1);

	printArray(array, size);
	mid = (size - 1) / 2;

	if (size == 1)
		return (array[mid] == value ? (int)mid : -1);

	if (array[mid] == value)
	{
		if (mid == 0 || array[mid - 1] != value)
			return (mid);
		else
			return (advanced_binary(array, mid + 1, value));
	}

	if (array[mid] > value)
		return (advanced_binary(array, mid + 1, value));

	if (array[mid] < value)
	{
		right = advanced_binary(array + mid + 1, size - mid - 1, value);
		return (right < 0 ? -1 : mid + right + 1);
	}
	return (-1);
}
