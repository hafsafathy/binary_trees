#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Right-rotates a binary tree.
 * @tree: pointer to the root.
 *
 * Return: pointer to the new root.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pp, *krr;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	pp = tree->left;
	krr = pp->right;
	pp->right = tree;
	tree->left = krr;
	if (krr != NULL)
		krr->parent = tree;
	krr = tree->parent;
	tree->parent = pp;
	pp->parent = krr;
	if (krr != NULL)
	{
		if (krr->left == tree)
			krr->left = pp;
		else
			krr->right = pp;
	}

	return (pp);
}
