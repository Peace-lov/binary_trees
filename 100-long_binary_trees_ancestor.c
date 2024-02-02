#include "binary_trees.h"

size_t depth(const binary_tree_t *tree);

/**
 * binary_trees_ancestor - Finds the lowest
 * common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: null if no common ancestors,
 * else return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t
		*first, const binary_tree_t *second)
{
	size_t first_dep, second_dep;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);
	if (first->parent == second->parent)
		return ((binary_tree_t *)first->parent);
	if (first == second->parent)
		return ((binary_tree_t *)first);
	if (first->parent == second)
		return ((binary_tree_t *)second);

	for (first_dep = depth(first); first_dep > 1; first_dep--)
		first = first->parent;
	for (second_dep = dep(second); second_dep > 1; second_dep--)
		second = second->parent;

	if (first == second)
		return ((binary_tree_t *)first);
	if (first->parent == second->parent)
		return ((binary_tree_t *)first->parent);
	if (first == second->parent)
		return ((binary_tree_t *)first);
	if (first->parent == second)
		return ((binary_tree_t *)second);
	else
		return (NULL);
}

/**
 * depth - take measurement for the depth of a node.
 * @tree: pointer to the node.
 *
 * Return: 0 if tree is NULL, else the depth.
 */
size_t depth(const binary_tree_t *tree)
{
	return ((tree->parent != NULL) ? 1 + depth(tree->parent) : 0);
}
