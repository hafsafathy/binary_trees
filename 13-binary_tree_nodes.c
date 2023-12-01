#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree.
 * @tree: pointer to the root.
 *
 * Return: If tree is NULL, the function must return 0.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nn = 0;

	if (tree)
	{
		nn += (tree->left || tree->right) ? 1 : 0;
		nn += binary_tree_nodes(tree->left);
		nn += binary_tree_nodes(tree->right);
	}
	return (nn);
}
