#include "monty.h"
/**
 * op_file - Open a file.
 * @file_name: String with the name of the file.
 */
void op_file(char *file_name)
{
	int file_check;
	FILE *fd;

	if (file_name == NULL)
		error_salida(2, file_name);

	file_check = access(file_name, R_OK);
	if (file_check == -1)
		error_salida(2, file_name);
	fd = fopen(file_name, "r");
	if (fd == NULL)
		error_salida(2, file_name);
	r_file(fd);

	fclose(fd);
}
/**
 * r_file - Read the content
 * @fd: Pointer to a file descriptor
 */
void r_file(FILE *fd)
{
	int n_line;
	int format = 0;
	char *buffer = NULL;
	size_t n = 0;

	if (fd == NULL)
		error_salida(2, "file_name");
	/*Read line by line*/
	for (n_line = 1; getline(&buffer, &n, fd) != EOF; n_line++)
	{
		format = int_line(buffer, n_line, format);
	}
	free(buffer);
}
/**
 * int_line - interpret each line by separating it one by one
 * @string: String on the line to be read
 * @n_line: line number for the opcode.
 * @format: Format specifier:
 * If the value is 0 --> Stack
 * If the value is 1 --> Queue
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */
int int_line(char *string, int n_line, int format)
{
	char *op_code;
	char *cmd;
	const char *del;

	del = "\n ";

	if (string == NULL)
		error_salida(4);

	op_code = strtok(string, del);

	if (op_code == NULL)
		return (format);

	cmd = strtok(NULL, del);
	if (strcmp(op_code, "queue") == 0)
		return (1);
	else if (strcmp(op_code, "stack") == 0)
		return (0);

	srch_func(op_code, cmd, n_line, format);
	return (format);
}
