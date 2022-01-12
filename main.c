#include "monty.h"

/**
 * main - Entry 2 the program.
 * @argc: Number of command line arguments.
 * @argv: An array containing the arg.
 * Return: Allways zero.
 */
int main(int argc, char **argv)
{
	FILE *fo = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
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

}
