#include "monty.h"

/**
* pall - Print all values on the stack starting from the top
* @stack: Double pointer to the head of the stack
* @line_number: Line number being executed from script file
*
* Return: void
*/
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *head;

(void)(line_number); // To avoid unused variable warning

head = *stack;
while (head != NULL)
{
printf("%d\n", head->n);
head = head->next;
}
}

