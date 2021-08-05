#include "binary_trees.h"

/**
*heap_insert-insert in max heap
*Return:pointer to new node
*@root:tree
*@value:value
*/
heap_t *heap_insert(heap_t **root, int value)
{
	int temp, leftSize, rightSize, iscomplete, isFull;
	heap_t *new;

	if (root == NULL)
		return (NULL);
	if (!(*root))
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	leftSize = binary_tree_size((*root)->left);
	rightSize = binary_tree_size((*root)->right);
	iscomplete = isComplete((*root)->left, 0, binary_tree_size((*root)->left));
	isFull = binary_tree_is_full((*root)->left);
	if ((leftSize == rightSize && iscomplete) || leftSize == rightSize ||
		 (leftSize != rightSize && !isFull))
	{
		new = heap_insert(&((*root)->left), value);
		if (new->parent == NULL)
		{
			(*root)->left = new;
			new->parent = (*root);
		}
		if (new->parent->n < new->n)
		{
			temp = new->n;
			new->n = new->parent->n;
			new->parent->n = temp;
			return (new->parent);
		}
		else
			return (new);
	}
	else
	{
		new = heap_insert(&((*root)->right), value);
		if (new->parent == NULL)
		{
			(*root)->right = new;
			new->parent = (*root);
		}
		if (new->parent->n < new->n)
		{
			temp = new->n;
			new->n = new->parent->n;
			new->parent->n = temp;
			return (new->parent);
		}
		else
			return (new);
	}
}

/**
 * binary_tree_size - prints out the total number of nodes from tree root
 * @tree: input tree to printout
 * Return: tree size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
*isCompletene-tests completeness
*Return: 1 for complete else 0
*@tree:tree
*@index:index
*@nodes:number of nodes
*/
int isComplete(const binary_tree_t *tree, int index, int nodes)
{
	if (tree == NULL)
		return (1);
	if (index >= nodes)
		return (0);
	return (isComplete(tree->left, 2 * index + 1, nodes) &&
		isComplete(tree->right, 2 * index + 2, nodes));
}

/**
 * binary_tree_is_full - checks if the tree has every node filled
 * @tree: input tree to printout
 * Return: 1 if true, else false
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	return (0);
}
