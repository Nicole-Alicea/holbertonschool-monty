#include "monty.h"

/**
 * exe - Executes different operations based on the
 * value of the 'opcode' parameter
 * @line: String representing the operation to be performed
 * @stack: Double pointer to a stack data structure
 * @line_number: File's line number
 * @arg: String argument
 *
 * Return: void
 */

int exe(char *line,char *arg, stack_t **stack, unsigned int line_number, FILE *file)
{
	if (strcmp(line, "push") == 0)
	{
	  push(stack, line_number, arg);
	}
	else if (strcmp(line, "pall") == 0)
	{
		pall(stack, line_number);
	}
	else if (strcmp(line, "pint") == 0)
	{
		pint(stack, line_number);
	}
	else if (strcmp(line, "pop") == 0)
	{
		pop(stack, file, line, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number,
				line);
		exit(EXIT_FAILURE);
	}
	return (1);
}
