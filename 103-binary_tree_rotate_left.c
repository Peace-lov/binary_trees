#include "binary_trees.h"
/**
 * binary_tree_rotate_left - Left-rotates the tree.
 * @tree: pointer to the root.
 *
 * Return: pointer.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *piv, *tempu;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	piv = tree->right;
	tempu = piv->left;
	piv->left = tree;
	tree->right = tempu;
	if (tempu != NULL)
		tempu->parent = tree;
	tempu = tree->parent;
	tree->parent = piv;
	piv->parent = tempu;
	if (tempu != NULL)
	{
		if (tempu->left == tree)
			tempu->left = piv;
		else
			tempu->right = piv;
	}
	return (piv);
}
