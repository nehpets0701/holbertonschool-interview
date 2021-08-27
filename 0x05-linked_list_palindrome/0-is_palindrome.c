#include "lists.h"

/**
*is_palindrome-tells if linked list is palindrome
*Return:0/1
*@head:input list
*/
int is_palindrome(listint_t **head)
{
	int count = 0;
	listint_t *h = *head;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	if (count == 0 || count == 1)
		return (1);
	return (check(head, *head));
}

/**
*check-checks recursively
*Return:0/1
*@left:left
*@right:right
*/
int check(listint_t **left, listint_t *right)
{
	int first, second;

	if (right == NULL)
		return (1);

	first = check(left, right->next);
	if (first == 0)
		return (0);

	if (right->n == (*left)->n)
		second = 1;
	else
		second = 0;

	*left = (*left)->next;
	return (second);
}
