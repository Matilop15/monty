#include "monty.h"

/**
 * srch_func - Finds for the function to be executed
 * @op_code: The operation code, It could be push, pall, ...
 * @cmd: The possible value for the operation.
 * @n_line: Line number for the opcode.
 * @format: Format specifier:
 * If the value is 0 --> Stack
 * If the value is 1 --> Queue
 */
void srch_func(char *op_code, char *cmd, int n_line, int format)
{
	int i;
	int error;

	instruction_t functions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divide},
		{NULL, NULL}
	};
	if (op_code[0] == '#')
		return;

	for (error = 1, i = 0; functions[i].opcode != NULL; i++)
	{
		if (strcmp(op_code, functions[i].opcode) == 0)
		{
			find_func(functions[i].f, op_code, cmd, n_line, format);
			error = 0;
		}
	}
	if (error == 1)
	{
		error_salida(3, n_line, op_code);
	}
}

/**
 * find_func - Calls the required function.
 * @f: Pointer to the function that is about to be called.
 * @op_code: string representing the opcode.
 * @cmd: string representing a numeric value.
 * @n_line: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void find_func(op_func f, char *op_code, char *cmd, int n_line, int format)
{
	stack_t *node;
	int error;
	int i;

	error = 1;
	if (strcmp(op_code, "push") == 0)
	{
		/*Checks if the number is negative and moves the val ptr*/
		if (cmd != NULL && cmd[0] == '-')
		{
			cmd = cmd + 1;
			error = -1;
		}
		/*val is not a digit is the return value is 0*/
		if (cmd == NULL)
		{
			error_salida(5, n_line);
		}


		for (i = 0; cmd[i] != '\0'; i++)
		{
			if (isdigit(cmd[i]) == 0)
			{
				error_salida(5, n_line);
			}

		}

		/*Create new node*/
		node = new_node(atoi(cmd) * error);
		if (format == 0)
			f(&node, n_line);
		if (format == 1)
			add_queue(&node, n_line);
	}
	else
		f(&head, n_line);
}
