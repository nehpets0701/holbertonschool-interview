#include "binary_trees.h"

/**
*newNode-makes new node
*Return: pointer to new node
*@parent:parent
*@value:value
*/
avl_t *newNode(avl_t *parent, int value)
{
	avl_t *new = NULL;

	new = malloc(sizeof(avl_t));
	if (new == NULL)
		return (NULL);

	new->parent = parent;
	new->n = value;
	return (new);
}

/**
*makeAvl-makes an avl
*Return:pointer to new avl
*@parent:parent
*@array:input
*@first:first
*@last:last
*/
avl_t *makeAvl(avl_t *parent, int *array, int first, int last)
{
	int i;
	avl_t *new = NULL;

	if (last < first)
		return (NULL);

	i = (first + last) / 2;
	new = newNode(parent, array[i]);
	if (new == NULL)
		return (NULL);

	new->right = makeAvl(new, array, i + 1, last);
	new->left = makeAvl(new, array, first, i - 1);

	return (new);
}

/**
*sorted_array_to_avl-turns array to avl
*Return: tree
*@array:input
*@size:size
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{

}
