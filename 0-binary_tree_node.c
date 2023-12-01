#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node
 * @parent: pointer
 * @value: The value
 *
 * Return: If an error occurs - NULL
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *gd;

	gd = malloc(sizeof(binary_tree_t));
	if (gd == NULL)
		return (NULL);

	gd->n = value;
	gd->parent = parent;
	gd->left = NULL;
	gd->right = NULL;

	return (gd);
}
