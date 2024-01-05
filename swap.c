#include "monty.h"

/**
 * swap - This function swaps the top two elements of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: The line number
 *
 * Return: void
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *next;

	if (var.stack_len < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	if (var.stack_len == 2)
	{
		*stack = (*stack)->next;
		return;
	}
	next = (*stack)->next;
	next->prev = (*stack)->prev;
	(*stack)->prev->next = next;
	(*stack)->prev = next;
	(*stack)->next = next->next;
	next->next->prev = *stack;
	next->next = *stack;
	*stack = next;
}
