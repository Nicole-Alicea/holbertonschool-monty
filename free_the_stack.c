#include "monty.h"

/**
 * free_the_stack - This function will free the stack
 * @status: exit status
 * @arg: double pointer to the stack
 *
 * Return: void
 */

void free_the_stack(int status, void *arg)
{
	stack_t **stack;
	stack_t *next;

	(void)status;

	stack = (stack_t **)arg;
	if (*stack)
	{
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
	while (*stack != NULL)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
	var.stack_len = 0;
}
