#include "lists.h"

/**
 * check_cycle-checks if there is a cycle in a linked list
 * @list: head
 * Return: 0/1
 */
int check_cycle(listint_t *list)
{
	listint_t *first, *second;

	if (list == NULL)
		return (0);
	first = list;
	second = list;
	while (second->next != NULL)
	{
		first = first->next;
		second = second->next;
		if (second->next == NULL)
			break;
		second = second->next;
		if (first == second)
			return (1);
	}
	return (0);
}
