#include "monty.h"

/**
 * is_digit - Checks the string for integers
 * @arg: The string to be checked
 *
 * Return: O if an integer, 1 otherwise
 */

static int is_digit(char *arg)
{
	int x;

	for (x = 0; arg[x]; x++)
	{
		if (arg[x] == '-' && x == 0)
		{
			continue;
		}
		if (isdigit(arg[x]) == 0)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * push - This function will push an integer onto the stack
 * @stack: Double pointer to the beginning of the stack
 * @line_number: The line number
 *
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int i;

	arg = strtok(NULL, "\n\t\r ");
	if (arg == NULL || is_digit(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	i = atoi(arg);
	if (!add_node(stack, i))
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	var.stack_len++;
}
