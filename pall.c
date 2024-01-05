#include "monty.h"

/**
 * pall - This function prints all the values to the stack
 * @stack: Double pointer to the linked list stack
 * @line_number: File's line number
 *
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	(void)line_number;

	if (head == NULL)
	{
		return;
	}

	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
