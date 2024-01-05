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
	stack_t *head = *stack;
	int len = 0, temp;

	while (head)
	{
		head = head->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = head->n;
	head->n = head->next->n;
	head->next->n = temp;
}
