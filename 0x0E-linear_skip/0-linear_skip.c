#include "search.h"

/**
 * linear_skip-searches list skipping
 * @list:list to search
 * @value:value to look for
 * Return: pointer to node
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *last, *current;
	int found = 0;

	if (list == NULL)
		return (NULL);
	while (list->express != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				list->express->index, list->express->n);
		if (value > list->express->n)
			list = list->express;
		else
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
					list->index, list->express->index);
			found = 1;
			break;
		}
	}
	current = list;
	if (found == 0)
	{
		last = current;
		while (last->next != NULL)
			last = last->next;
		printf("Value found between indexes [%lu] and [%lu]\n",
				current->index, last->index);
	}
	while (current != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
		if (current->n == value)
			return (current);
		current = current->next;
	}
	return (NULL);
}
