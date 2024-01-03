#include "monty.h"

/**
 * pop - This function removes the top element of the stack
 * @stack: Double pointer to linked list stack
 * @line_number: File's line number
 *
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *s = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;

	if (*stack)
	{
		(*stack)->prev = NULL;
	}
	free(s);
}
