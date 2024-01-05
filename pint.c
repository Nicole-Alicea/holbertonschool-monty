#include "monty.h"

/**
 * pint - This function will print the value on top of the stack,
 * or exit if the stack is empty
 * @stack: Double pointer to the head of the stack
 * @line_number: The line number
 *
 * Return: void
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (var.stack_len == 0)
	{
		dprintf(STDOUT_FILENO, "L%u: can't pint, stack empty\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}
