#include "monty.h"

/**
 * push - Creates a new node with the provided integer value and pushes
 * it onto the top of the given stack
 * @stack: Double pointer to the top of the stack
 * @line_number: File's line number
 *
 * Return: void
 */

void push(stack_t **stack, const char *arg, unsigned int line_number,
		FILE *file, char *line)
{
	int x = 0, flag = 0;

	if (arg)
	{
		if (arg[0] == '-')
			x++;
		for (; arg[x] != '\0'; x++)
		{
			if (arg[x] > '9' || arg[x] < '0')
			{
				flag = 1;
			}
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(file);
			free(line);
			free_the_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
}
	/**stack_t *new_node = malloc(sizeof(stack_t));
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
	*stack = new_node;*/
