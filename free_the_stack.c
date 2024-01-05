#include "monty.h"

/**
 * free_the_stack - This function will free the stack
 * @stack: Stack to be freed
 *
 * Return: void
 */

 void free_the_stack(stack_t *stack)
{
	stack_t *temp;

	temp = stack;
	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
