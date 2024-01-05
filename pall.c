#include "monty.h"

/**
 * pall - This function prints all values on the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: The line number
 *
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	(void)line_number;

	head = *stack;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
		if (head == *stack)
		{
			return;
		}
	}
}
