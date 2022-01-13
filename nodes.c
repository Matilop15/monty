#include "monty.h"

/**
 * new_node - create a new node.
 * @head: pointer to
 * @n: Number to ho inside the node.
 * Return: On succes point to a node otherwise NULL.
 */
stack_t *new_node(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	if (*head == NULL)
	{
		new->n = n;
		new->next = NULL;
		new->prev = NULL;
		*head = new;
		free(new);
		return (*head);
	}

	(*head)->prev = new;
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	*head = new;
	free(new);
	return (*head);
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
