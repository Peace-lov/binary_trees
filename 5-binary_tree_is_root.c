#include "binary_trees.h"
/**
 * binary_tree_is_root - examines if a node is a root.
 * @node: pointer to the node.
 *
 * Return: 1 if node is the root else 0.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);

	return (1);
}
