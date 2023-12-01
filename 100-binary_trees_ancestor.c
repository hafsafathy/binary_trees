#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: If no common ancestors return NULL.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *ha, *fa;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	ha = first->parent, fa = second->parent;
	if (first == fa || !ha || (!ha->parent && fa))
		return (binary_trees_ancestor(first, fa));
	else if (ha == second || !fa || (!fa->parent && ha))
		return (binary_trees_ancestor(ha, second));
	return (binary_trees_ancestor(ha, fa));
}
