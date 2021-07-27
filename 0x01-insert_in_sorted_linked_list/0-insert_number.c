#include "lists.h"

/**
*insert_node-inserts node at correct position
*Return:pointer to new or null
*@head:head
*@number:number to insert
*/
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current = *head;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;

	while (current != NULL)
	{
		if (number < current->n)
		{
			new->next = *head;
			*head = new;
			return (new);
		}
		if (current->next)
		{
			if (number <= current->next->n)
			{
				new->next = current->next;
				current->next = new;
				return (new);
			}
			current = current->next;
		}
		else
		{
			new->next = NULL;
			current->next = new;
			return (new);
		}
	}
	new->next = NULL;
	*head = new;
	return (new);
}
