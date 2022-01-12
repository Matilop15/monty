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
 * push - push a integer to stack
 * @stack: pointer to stack
 * @line_number: line number of code
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char *arg;
	int push_arg = 0;
	(void) line_number;

	new = malloc(sizeof(stack_t));
	if (!new)
		error_salida(4, *stack);

	arg = strtok(NULL, "\n ");
	if (isnumber(arg) == 1 && arg != NULL)
	{
		push_arg = atoi(arg);
	}
	else
		error_salida(3, &stack);

	new_node(stack, push_arg);
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
