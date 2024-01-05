#include "monty.h"

/**
 * push - Creates a new node with the provided integer value and pushes
 * it onto the top of the given stack
 * @stack: Double pointer to the top of the stack
 * @line_number: File's line number
 *
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number, char *arg) {
    int num;

    if (arg == NULL || (num = atoi(arg), num == 0 && strcmp(arg, "0") != 0)) {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *new_node = (stack_t *) malloc(sizeof(stack_t));
    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = num;
    new_node->prev = NULL;
    new_node->next = *stack;
    if (*stack != NULL) {
        (*stack)->prev = new_node;
    }
    *stack = new_node;
}
