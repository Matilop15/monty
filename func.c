#include "monty.h"

/**
 * pall - Adds a node to the stack.
 * @stack: Pointer 2 linked list stack.
 * @line_number: Interger representing the line number of the code.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *recorre;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	recorre = *stack;
	while (recorre != NULL)
	{
		printf("%d\n", recorre->n);
		recorre = recorre->next;
	}
}
