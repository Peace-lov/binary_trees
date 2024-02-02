#include "binary_trees.h"
/**
 * binary_tree_leaves - numbers the leaves.
 * @tree: pointer to the root.
 *
 * Return: numb of leaves.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t lves = 0;

	if (tree)
	{
		lves += (!tree->left && !tree->right) ? 1 : 0;
		lves += binary_tree_leaves(tree->left);
		lves += binary_tree_leaves(tree->right);
	}
	return (lves);
}
