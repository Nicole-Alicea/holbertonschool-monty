#include "monty.h"
extern var_t var;

/**
* pint - Print value on top of `stack', or exit if stack is empty.
* @stack: Double pointer to head of stack.
* @line_number: Line number of current operation.
*
* Return: void.
*/
void pint(stack_t **stack, unsigned int line_number)
{
if (var.stack_len == 0)
{
dprintf(STDOUT_FILENO, "L%u: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
printf("%d\n", (*stack)->n);
}
