#include "monty.h"

/**
 * swap - Swap element 1 for element 2 of the stack
 * @stack: points to the top node of the stack.
 * @n_line: opcode line number.
 */
void swap(stack_t **stack, unsigned int n_line)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_salida2(8, n_line, "swap");

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;

	if (tmp->next != NULL)
		tmp->next->prev = *stack;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}
/**
 * add - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @n_line: Interger representing the line number of of the opcode.
 */
void add(stack_t **stack, unsigned int n_line)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_salida2(8, n_line, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * nop - does nothing
 * @stack: top of the stack
 * @n_line: current line number
 */
void nop(stack_t **stack, unsigned int n_line)
{
	(void)*stack;
	(void)n_line;
}
