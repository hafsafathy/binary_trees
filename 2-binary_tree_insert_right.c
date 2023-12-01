#include "binary_trees.h"

/**
 * binary_tree_insert_right - Insert a node as the right-child
 * of another in a binary tree.
 * @parent: A pointer
 * @value: value to store in the new node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 * Otherwise - pointer
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *gd;

	if (parent == NULL)
		return (NULL);

	gd  = binary_tree_node(parent, value);
	if (gd == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		gd->right = parent->right;
		parent->right->parent = gd;
	}
	parent->right = gd;

	return (gd);
}
