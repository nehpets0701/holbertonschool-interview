#include "binary_trees.h"

/**
 * height - height of tree
 * @node: node to check
 * Return: number of nodes
 */
int height(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	return (1 + MAX(height(node->left), height(node->right)));
}

/**
 * isBst - checks if tree is binary search tree
 * @tree: tree
 * @min: min
 * @max: max
 * Return: 0/1
 */
int isBst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->left != NULL && tree->left->n < min)
		return (0);
	if (tree->right != NULL && tree->right->n > max)
		return (0);

	return (isBst(tree->left, min, tree->n - 1) &&
			isBst(tree->right, tree->n + 1, max));
}

/**
 * isBalanced - check if tree is balanced
 * @tree: tree
 * Return: 0/1
 */
int isBalanced(const binary_tree_t *tree)
{
	int l, r;

	if (tree == NULL)
		return (1);

	l = height(tree->left);
	r = height(tree->right);

	if (abs(l - r) <= 1 && isBalanced(tree->left) &&
							 isBalanced(tree->right))
		return (1);

	return (0);
}

/**
 * binary_tree_is_avl - checks if tree is AVL tree
 * @tree: tree
 * Return: 0/1
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (is_tree_bst(tree, -10000, 10000) == 0)
		return (0);
	return (is_tree_avl(tree));
}
