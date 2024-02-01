#include "binary_trees.h"
/**
 * binary_tree_height - takesM masurement of the
 * height of a binary tree.
 * @tree: pointer to the root to measure the height.
 *
 * Return: 0 If tree is NULL, else height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l, r;

	if (tree)
	{
		l = 0, r = 0;

		l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((l > r) ? l : r);
	}
	return (0);
}
