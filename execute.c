#include "monty.h"

/**
 * exe - ...
 * @opcode: ...
 * @stack: ...
 * @line_number: ...
 * @arg: ...
 *
 * Return: void
 */

void exe(char *opcode, stack_t **stack, unsigned int line_number, char *arg)
{
	if (strcmp(opcode, "push") == 0)
	{
		push(stack, line_number, arg);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(stack, line_number);
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
