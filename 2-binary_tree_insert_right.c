#include "binary_trees.h"

/**
 * binary_tree_insert_right - put a node to the right child
 * of another in a binary tree.
 * @parent: pointer to the node to put the right child in.
 * @value: value to store in the new node.
 *
 * Return: NULL if parent or an error occurs else
 * a pointer to the new node.
 *
 * Description: If parent already has a right child, the new node
 * takes its place and the old right child is set as
 * the right child of the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *nw;

	if (parent == NULL)
		return (NULL);

	nw = binary_tree_node(parent, value);
	if (nw == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		nw->right = parent->right;
		parent->right->parent = nw;
	}
	parent->right = nw;

	return (nw);
}
