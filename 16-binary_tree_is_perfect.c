#include "binary_trees.h"

unsigned char is_lef(const binary_tree_t *node);
size_t dth(const binary_tree_t *tree);
const binary_tree_t *get_lef(const binary_tree_t *tree);
int is_perfect(const binary_tree_t *tree,
		size_t lef_depth, size_t lvl);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * is_lef - Checks if a node is a leaf of a binary tree.
 * @node: pointer to the node.
 *
 * Return: If the node is a leaf, 1, otherwise, 0.
 */
unsigned char is_lef(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * dth - Returns the depth of a given
 * @tree: A pointer to the node to measure the depth of.
 *
 * Return: The depth of node.
 */
size_t dth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + dth(tree->parent) : 0);
}

/**
 * get_lef - Returns a leaf of a binary tree.
 * @tree: pointer to the root.
 *
 * Return: pointer to the first encountered leaf.
 */
const binary_tree_t *get_lef(const binary_tree_t *tree)
{
	if (is_lef(tree) == 1)
		return (tree);
	return (tree->left ? get_lef(tree->left) : get_lef(tree->right));
}

/**
 * is_perfect - Checks if a binary tree is perfect.
 * @tree: pointer to the root.
 * @lef_depth: depth of one leaf in the binary tree.
 * @lvl: Level of current node.
 *
 * Return: If the tree is perfect, 1, otherwise 0.
 */
int is_perfect(const binary_tree_t *tree,
		size_t lef_depth, size_t lvl)
{
	if (is_lef(tree))
		return (lvl == lef_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect(tree->left, lef_depth, lvl + 1) &&
		is_perfect(tree->right, lef_depth, lvl + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL or not perfect, 0.
 *         Otherwise, 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect(tree, dth(get_lef(tree)), 0));
}
