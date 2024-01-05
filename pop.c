#include "monty.h"

/**
 * pop - This function removes the top element of the stack
 * @stack: Double pointer to head of the stack
 * @line_number: The line number
 *
 * Return: void
 */

void pop(stack_t **stack, FILE *file, char *line, unsigned int line_number)
{
	stack_t *head = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop empty stack\n", line_number);
		fclose(file);
		free(line);
		free_the_stack(*stack);
		exit(EXIT_FAILURE);
	}
	*stack = head->next;
	free(head);
}
