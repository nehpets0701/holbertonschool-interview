#include "binary_trees.h"

/**
 * binary_tree_node-makes a node in a binary tree
 * Return:new struct node
 * @parent:input parent
 * @value:value to put in node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);
	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
