#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes a binary tree.
 * @tree: pointer
 * Return: no return
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
