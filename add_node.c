#include "monty.h"

/**
 * add_node - The function will add the node to the beginning if in
 * stack mode and the end if in queve mode
 * @stack: double pointer to the beginning
 * @n: Value to add to the new mode
 *
 * Return: pointer to the new node, or NULL on failure
 */

stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new;

	if (stack == NULL)
	{
		return (NULL);
	}
	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		return (NULL);
	}
	new->n = n;
	if (*stack == NULL)
	{
		new->prev = new;
		new->next = new;
	}
	else
	{
		(*stack)->prev->next = new;
		new->prev = (*stack)->prev;
		(*stack)->prev = new;
		new->next = *stack;
	}
	if (var.queue == STACK || var.stack_len == 0)
		*stack = new;
	return (new);
}
