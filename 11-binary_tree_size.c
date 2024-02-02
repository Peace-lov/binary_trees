#include "binary_trees.h"
/**
 * binary_tree_size - takes measurement of the size
 * of a binary tree.
 * @tree: pointer to the root.
 *
 * Return: The sz of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t sz = 0;

	if (tree)
	{
		sz += 1;
		sz += binary_tree_size(tree->left);
		sz += binary_tree_size(tree->right);
	}
	return (sz);
}
