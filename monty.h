#ifndef MONTY_H
#define MONTY_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



typedef struct var_s {
  int queue; 
  size_t stack_len; 
} var_t;

#define STACK 0
#define QUEUE 1

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push(stack_t **stack, unsigned int line_number, char *arg);

void pall(stack_t **stack, unsigned int line_number);

int exe(char *line, char *arg, stack_t **stack, unsigned int line_number,
		FILE *file);

int is_integer(const char *arg);

void pint(stack_t **stack, unsigned int line_number);

void pop(stack_t **stack, FILE *file, char *line, unsigned int line_number);

void nop(stack_t **stack, unsigned int line_number);

void swap(stack_t **stack, unsigned int line_number);

void add(stack_t **stack, unsigned int line_number);

void free_the_stack(stack_t *stack);

#endif
