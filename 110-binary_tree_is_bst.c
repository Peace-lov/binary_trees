#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst_helper - examines if the tree
 * is a valid binary search tree.
 * @tree: pointer to the root node.
 * @lo: value of the smallst node
 * visited thus far.
 * @hi: value of the largst node
 * visited this far.
 *
 * Return: 1 if the tree is a valid BST, else 0.
 */
int is_bst_helper(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		return (is_bst_helper(tree->left, lo, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_bst - examines if the tree
 * is a valid binary search tree.
 * @tree: pointer to the root node.
 *
 * Return: 1 if tree is a valid BST, else 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
