#include "monty.h"
stack_t *head = NULL;

/**
 * main - Entry 2 the program.
 * @argc: Number of command line arguments.
 * @argv: An array containing the arg.
 * Return: Allways zero.
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;

	if (argc != 2)
		error_salida(1);
	lec_file(argv[1], &stack);
	free_node();
	printf("funciono");
	return (0);
}
