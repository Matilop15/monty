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
	{
		exit(EXIT_FAILURE);
	}

	recorre = *stack;
	while (recorre)
	{
		printf("%d\n", recorre->n);
		recorre = recorre->next;
	}
}
/**
 * push - Push a integer 2 stack.
 * @stack: Pointer 2 stack.
 * @line_number: Line number of code.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char *arg;
	int push_arg = 0;

	new = malloc(sizeof(stack_t));
	if (!new)
		error_salida(4, *stack);

	arg = strtok(NULL, "\n ");
	if (isnumber(arg) == 1 && arg != NULL)
	{
		push_arg = atoi(arg);
	}
	else
		error_salida(5, line_number);

	new_node(stack, push_arg);
}
/**
 * pint - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		error_salida(6, line_number);

	printf("%d\n", (*stack)->n);
}
/**
 * isnumber - checks if a string is a number
 * @str: string being passed
 *
 * Return: returns 1 if string is a number, 0 otherwise
 */
int isnumber(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
