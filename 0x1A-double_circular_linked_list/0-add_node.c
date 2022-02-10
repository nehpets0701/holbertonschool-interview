#include "list.h"

/**
 * newNodeEnd - Adds node to end of double circular linked list
 * @list:input
 * @str:string to input
 * Return: new node or NULL
 */
List *newNodeEnd(List **list, char *str)
{
	List *new;

	if (list == NULL)
		return (NULL);

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}
	new->next = new;
	new->prev = new;

	if (*list == NULL)
		*list = new;
	else
	{
		new->next = *list;
		new->prev = (*list)->prev;
		(*list)->prev->next = new;
		(*list)->prev = new;
	}
	return (new);
}

/**
 * newNodeStart-adds node at start of double circular list
 * @list:input
 * @str:string to input
 * Return: new node or NULL
 */
List *newNodeStart(List **list, char *str)
{
	List *new;

	if (list == NULL)
		return (NULL);

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}
	new->next = new;
	new->prev = new;

	if (*list == NULL)
		*list = new;
	else
	{
		new->next = *list;
		new->prev = (*list)->prev;
		(*list)->prev->next = new;
		(*list)->prev = new;
		*list = new;
	}
	return (new);
}
