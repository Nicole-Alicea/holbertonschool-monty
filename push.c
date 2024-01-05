#include "monty.h"
#include <ctype.h>

/**
* check_for_digit - checks that a string only contains digits
* @arg: string to check
* Return: 0 if only digits, else 1
*/
static int check_for_digit(char *arg)
{
int i;

for (i = 0; arg[i]; i++)
{
if (arg[i] == '-' && i == 0)
continue;
if (!isdigit(arg[i]))
return (1);
}
return (0);
}

/**
* push - push an integer onto the stack
* @stack: double pointer to the beginning of the stack
* @line_number: script line number
*/
void push(stack_t **stack, unsigned int line_number)
{
char *arg;
int num;

arg = strtok(NULL, "\n\t\r ");
if (arg == NULL || check_for_digit(arg))
{
dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
num = atoi(arg);

stack_t *new_node = (stack_t *) malloc(sizeof(stack_t));
if (new_node == NULL)
{
dprintf(STDERR_FILENO, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = num;
new_node->prev = NULL;
new_node->next = *stack;
if (*stack != NULL)
{
(*stack)->prev = new_node;
}
*stack = new_node;
}
