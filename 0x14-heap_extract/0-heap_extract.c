#include "binary_trees.h"

/**
 * countNodes - counts the numeber of nodes
 * @root: input
 * Return: number of nodes
 */
unsigned int countNodes(heap_t *root)
{
	if (root == NULL)
		return (0);
	return (1 + countNodes(root->left) + countNodes(root->right));
}

/**
 * findLast - finds last node
 * @root: input
 * Return: last node
 */
heap_t *findLast(heap_t *root)
{
	unsigned int count, binary = 1;

	count = countNodes(root);
	while (count / binary > 1)
		binary = binary << 1;
	binary = binary >> 1;

	while (binary)
	{
		if (count & binary)
			root = root->right;
		else
			root = root->left;
		binary = binary >> 1;
	}
	return (root);
}

/**
 * preorder - finds last node
 * @root: input
 * Return: last node
 */
void preorder(heap_t *root)
{
	heap_t *swap = root;
	int temp;

	if (root->left && root->right)
	{
		if (root->left->n >= root->right->n)
		{
			if (root->left->n > root->n)
				swap = root->left;
		}
		else
		{
			if (root->right->n > root->n)
				swap = root->right;
		}
	}
	else if (root->left && root->left->n > root->n)
		swap = root->left;
	else if (root->right && root->right->n > root->n)
		swap = root->right;

	if (swap != root)
	{
		temp = root->n;
		root->n = swap->n;
		swap->n = temp;
		preorder(swap);
	}
}

/**
 * heap_extract - extracts the root node of binary heap
 * @root: input
 * Return: number in root or 0
 */
int heap_extract(heap_t **root)
{
	heap_t *last;
	int ret;

	if (root == NULL || *root == NULL)
		return (0);
	last = findLast(*root);
	ret = (*root)->n;
	if (last == *root)
	{
		free(*root);
		*root = NULL;
	}
	else
	{
		if (last->parent->left == last)
			last->parent->left = NULL;
		else
			last->parent->right = NULL;
		last->parent = NULL;

		if ((*root)->left == last)
			last->left = NULL;
		else
			last->left = (*root)->left;
		if ((*root)->right == last)
			last->right = NULL;
		else
			last->right = (*root)->right;

		if (last->left != NULL)
			last->left->parent = last;
		if (last->right != NULL)
			last->right->parent = last;
		free(*root);
		*root = last;
		preorder(last);
	}
	return (ret);
}
