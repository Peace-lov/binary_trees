#include "binary_trees.h"
/**
 * binary_tree_rotate_right - Right rotates tree.
 * @tree: pointer to the root.
 *
 * Return: pointer.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *piv, *tempu;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	piv = tree->left;
	tempu = piv->right;
	piv->right = tree;
	tree->left = tempu;
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
