#include "monty.h"

/**
 * main - Entry 2 the program.
 * @argc: Number of command line arguments.
 * @argv: An array containing the arg.
 * Return: Allways zero.
 */
int main(int argc, char **argv)
{
<<<<<<< HEAD
	stack_t *stack
=======
	FILE *fo = NULL;
>>>>>>> e3c0846687f4e58af34c988ce9c02198cce5e850

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
<<<<<<< HEAD
		exit_type(&string);
	}
=======
		exit(EXIT_FAILURE);
	}
	fo = fopen(argv[1], "r"); /** r para abrir y leer */
	if (fo == NULL)
	{
		dprintf(STDOUT_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	else
		llamar a struct 

>>>>>>> e3c0846687f4e58af34c988ce9c02198cce5e850
}
