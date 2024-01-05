#include "monty.h"

/**
 * swap - This function swaps the top two elements of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: The line number
 *
 * Return: void
 */

void swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}
/**void swap(stack_t **stack, unsigned int line_number)
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
}*/
