#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst - Checks .
 * @tree: pointer to the root node.
 * @low: value of the smallest node visited thus far.
 * @high: value of the largest node visited this far.
 *
 * Return: If the tree is a valid BST, 1, otherwise, 0.
 */
int is_bst(const binary_tree_t *tree, int low, int high)
{
	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);
		return (is_bst(tree->left, low, tree->n - 1) &&
			is_bst(tree->right, tree->n + 1, high));
	}
	return (1);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid binary search tree.
 * @tree: pointer to the root.
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst(tree, INT_MIN, INT_MAX));
}
