#include "binary_trees.h"

/**
 * struct node_s - singly linked list
 * @node: const binary tree node
 * @next: points to the next node
 */
typedef struct node_s
{
	const binary_tree_t *node;
	struct node_s *next;
} ll;

ll *append(ll *head, const binary_tree_t *btnode);
void free_list(ll *head);
ll *get_children(ll *head, const binary_tree_t *parent);
void levels_rec(ll *head, void (*func)(int));

/**
 * binary_tree_levelorder - using level-order to traversal.
 * @tree: A pointer to the root.
 * @func: A pointer to a function to call.
 */
void binary_tree_levelorder(const binary_tree_t *tree,
		void (*func)(int))
{
	ll *chdren = NULL;

	func(tree->n);
	chdren = get_children(chdren, tree);
	levels_rec(chdren, func);

	free_list(chdren);
}

/**
 * levels_rec - Calls func on each nodes at each level.
 * @head: A pointer to head of linked list.
 * @func: A pointer to a function to call.
 */
void levels_rec(ll *head, void (*func)(int))
{
	ll *chdren = NULL, *cur = NULL;

	if (!head)
		return;
	for (cur = head; cur != NULL; cur = cur->next)
	{
		func(cur->node->n);
		chdren = get_children(chdren, cur->node);
	}
	levels_rec(chdren, func);
	free_list(chdren);
}

/**
 * get_children - appends children parent
 * to linked list.
 * @head: A pointer to head of linked list.
 * @parent: A pointer to node.
 * Return: A pointer to head of
 * linked of children.
 */
ll *get_children(ll *head, const binary_tree_t *parent)
{
	if (parent->left)
		head = append(head, parent->left);
	if (parent->right)
		head = append(head, parent->right);
	return (head);
}

/**
 * append - attach node at the end of a (linkedlist)
 * @head: A pointer to the head of linked list
 * @btnode: const node to append
 * Return: pointer, else NULL.
 */
ll *append(ll *head, const binary_tree_t *btnode)
{
	ll *nw = NULL, *lst = NULL;

	nw = malloc(sizeof(*nw));
	if (nw)
	{
		nw->node = btnode;
		nw->next = NULL;
		if (!head)
			head = nw;
		else
		{
			lst = head;
			while (lst->next)
				lst = lst->next;
			lst->next = nw;
		}
	}
	return (head);
}

/**
 * free_list - frees all the nodes (linked list)
 * @head: A pointer to the head of linked list
 */
void free_list(ll *head)
{
	ll *pitr = NULL;

	while (head)
	{
		pitr = head->next;
		free(head);
		head = pitr;
	}
}
