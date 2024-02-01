#include "binary_trees.h"

/**
 * binary_tree_node - makes a binary tree node.
 * @parent: pointer to the parent of the node to make.
 * @value: The val to put in the node you created.
 *
 * Return: An error occurs return NULL, else a pointer.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *nw;

	nw = malloc(sizeof(binary_tree_t));
	if (nw == NULL)
		return (NULL);

	nw->n = value;
	nw->parent = parent;
	nw->left = NULL;
	nw->right = NULL;

	return (nw);
}
