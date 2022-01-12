#include "monty.h"

/**
 * lec_file - read file and execute commands
 * @filename: pathname to file
 * @stack: pointer a la parte superior del stack (pila(
 */
void read_file(char *filename, stack_t **stack)
{
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		exit_type(stack);
	}
:x

