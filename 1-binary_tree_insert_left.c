#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as a left-child of
 * another in a binary tree.
 * @parent: A pointer to the node to insert the left-child in.
 * @value: The value to store in the new node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 * Otherwise - a pointer.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *gd;

	if (parent == NULL)
		return (NULL);

	gd  = binary_tree_node(parent, value);
	if (gd == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		gd->left = parent->left;
		parent->left->parent = gd;
	}
	parent->left = gd;

	return (gd);
}
