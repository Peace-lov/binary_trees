#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
void pop(levelorder_queue_t **head);
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * create_node - makes a new
 * levelorder_queue_t node.
 * @node: pointer to tree node
 * for the new node to contain.
 * Return: null if an error occurs,
 *         Otherwise, a pointer.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *nw;

	nw = malloc(sizeof(levelorder_queue_t));
	if (nw == NULL)
		return (NULL);

	nw->node = node;
	nw->next = NULL;

	return (nw);
}

/**
 * free_queue - Frees a levelorder_queue_t.
 * @head: pointer to queue head.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tempu;

	while (head != NULL)
	{
		tempu = head->next;
		free(head);
		head = tempu;
	}
}

/**
 * push - Pushes node to the back
 * of a levelorder_queue_t.
 * @node: pointer to tree node to print and push.
 * @head: double pointer to the head of queue.
 * @tail: double pointer to the tail of queue.
 *
 * Description: Upon malloc failure,
 * exits with a status code of 1.
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *nw;

	nw = create_node(node);
	if (nw == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = nw;
	*tail = nw;
}

/**
 * pop - Pops head of a levelorder_queue_t.
 * @head: double pointer to queue head.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *temp;

	temp = (*head)->next;
	free(*head);
	*head = temp;
}

/**
 * binary_tree_is_complete - examines if
 * tree is complete.
 * @tree: pointer to the root.
 *
 * Return: 0 if the tree is NULL or not complete,
 *         els 1.
 *
 * Description: Upon malloc failure,
 * exits with a status code of 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *hd, *tl;
	unsigned char flg = 0;

	if (tree == NULL)
		return (0);

	hd = tl = create_node((binary_tree_t *)tree);
	if (hd == NULL)
		exit(1);

	while (hd != NULL)
	{
		if (hd->node->left != NULL)
		{
			if (flg == 1)
			{
				free_queue(hd);
				return (0);
			}
			push(hd->node->left, hd, &tl);
		}
		else
			flg = 1;
		if (hd->node->right != NULL)
		{
			if (flg == 1)
			{
				free_queue(hd);
				return (0);
			}
			push(hd->node->right, hd, &tl);
		}
		else
			flg = 1;
		pop(&hd);
	}
	return (1);
}
