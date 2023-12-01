#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: pointer to the root.
 *
 * Return: If tree is NULL, return 0.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: pointer to the root.
 *
 * Return: If tree is NULL, your function must return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t eft = 0, rght = 0;

		eft = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		rght = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((eft > rght) ? eft : rght);
	}
	return (0);
}
