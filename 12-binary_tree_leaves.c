#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 * @tree: pointer to the root.
 *
 * Return: number of leaves in the tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t froa = 0;

	if (tree)
	{
		froa += (!tree->left && !tree->right) ? 1 : 0;
		froa += binary_tree_leaves(tree->left);
		froa += binary_tree_leaves(tree->right);
	}
	return (froa);
}
