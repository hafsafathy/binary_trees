#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree:double pointer to the root.
 * @value: value to store in the node.
 *
 * Return: pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *kly, *gd;

	if (tree != NULL)
	{
		kly = *tree;

		if (kly == NULL)
		{
			gd = binary_tree_node(kly, value);
			if (gd == NULL)
				return (NULL);
			return (*tree = gd);
		}

		if (value < kly->n)
		{
			if (kly->left != NULL)
				return (bst_insert(&kly->left, value));

			gd = binary_tree_node(kly, value);
			if (gd == NULL)
				return (NULL);
			return (kly->left = gd);
		}
		if (value > kly->n)
		{
			if (kly->right != NULL)
				return (bst_insert(&kly->right, value));

			gd = binary_tree_node(kly, value);
			if (gd == NULL)
				return (NULL);
			return (kly->right = gd);
		}
	}
	return (NULL);
}
