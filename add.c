#include "monty.h"

/**
 * add - This function adds the top two elements of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: The line number
 *
 * Return: void
 */

void add(stack_t **stack, unsigned int line_number)
{
	int n = 0;

	if (var.stack_len < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	n += (*stack)->n;
	pop(stack, line_number);
	(*stack)->n += n;
}
