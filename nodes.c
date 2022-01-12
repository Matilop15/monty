#include "monty.h"

/**
 * new_node - create a new node.
 * @n: Number to ho inside the node.
 * Return: On succes point to a node otherwise NULL.
 */
stack_t *new_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_node - Free a list.
 *
 */
void free_node(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
