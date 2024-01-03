#include "monty.h"

/**
 * push - ...
 * @stack: ...
 * @line_number: ...
 * @arg: ...
 *
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number, const char *arg)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	int value = atoi(arg);

	if (!is_integer(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
