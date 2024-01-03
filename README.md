# C - Stacks, Queues - LIFO, FIFO

### Description
We have been divided into groups to work on this project related to the data structures "LIFO" and "FIFO". In C, a "LIFO" structure is often implemented using a stack, which is a data structure where the last element added is the first one to be removed. A way to better understand this is to imagine a stack of books. You can only add or remove from the top. If you want to reach the book at the bottom, you will have to remove all of the books on top of it one by one. The functions that are typically implemented are 'push' (to add an element to the top of the stack) and 'pop' (to remove the last-added element).

In C, a "FIFO" structure is often implemented using a queue, which is a data structure where the first added element is the first one to be removed. To visualize this, imagine people waiting in a queue. The first person who joined the queue will be the first one to proceed. The queue operations use functions like 'enqueue' (to add an element to the rear of the queue) and 'dequeue' (to remove the first-added element in the queue).  

---------------------------------
### Resources
[How do I use extern to share variables between source files in C?](https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files)

---------------------------------
## Learning Objectives
### General
- What do LIFO and FIFO mean.
- What is a stack, and when to use it.
- What is a queue, and when to use it.
- What are the common implementations of stacks and queues.
- What are the most common use cases of stacks and queues.
- What is the proper way to use global variables.
--------------------------------
## Requirements
### General
- Allowed editors: vi, vim, emacs.
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic.
- All your files should end with a new line.
- A README.md file, at the root of the folder of the project is mandatory.
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl.
- You allowed to use a maximum of one global variable.
- No more than 5 functions per file.
- You are allowed to use the C standard library.
- The prototypes of all your functions should be included in your header file called monty.h.
- Don’t forget to push your header file.
- All your header files should be include guarded.
- You are expected to do the tasks in the order shown in the project.
-------------------------------
## More Info
### Data Structures
The following data structures are used in this project:

typedef struct stack_s

{

        int n;
        
        struct stack_s *prev;
        
        struct stack_s *next;
        
} stack_t;

typedef struct instruction_s

{

        char *opcode;
        
        void (*f)(stack_t **stack, unsigned int line_number);
        
} instruction_t;

## Compilation & Output
- The code will be compiled this way:

  *$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty**

- Any output must be printed on stdout.
- Any error message must be printed on stderr.

#### Tasks

-----------------------------

0. #### push, pall
Implement the push and pall opcodes.

The push opcode

The opcode push pushes an element to the stack.
- Usage: push <int>
  - where <int> is an integer
- if <int> is not an integer or if there is no argument given to push, print the error message L<line_number>: usage: push integer, followed by a new line, and exit with the status EXIT_FAILURE
  - where is the line number in the file
- You won’t have to deal with overflows. Use the atoi function
The pall opcode

The opcode pall prints all the values on the stack, starting from the top of the stack.
- Usage pall
- Format: see example
- If the stack is empty, don’t print anything

1. #### pint
Implement the pint opcode.

The pint opcode

The opcode pint prints the value at the top of the stack, followed by a new line.
- Usage: pint
- If the stack is empty, print the error message L<line_number>: can't pint, stack empty, followed by a new line, and exit with the status EXIT_FAILURE

2. #### pop
Implement the pop opcode.

The pop opcode

The opcode pop removes the top element of the stack.
- Usage: pop
- If the stack is empty, print the error message L<line_number>: can't pop an empty stack, followed by a new line, and exit with the status EXIT_FAILURE

3. #### swap
Implement the swap opcode.

The swap opcode

The opcode swap swaps the top two elements of the stack.
- Usage: swap
- If the stack contains less than two elements, print the error message L<line_number>: can't swap, stack too short, followed by a new line, and exit with the status EXIT_FAILURE

4. #### add
Implement the add opcode.

The add opcode

The opcode add adds the top two elements of the stack.
- Usage: add
- If the stack contains less than two elements, print the error message L<line_number>: can't add, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
  - The top element of the stack contains the result
  - The stack is one element shorter

5. #### nop
Implement the nop opcode.

The nop opcode

The opcode nop doesn’t do anything.
- Usage: nop

### Authors &copy;

- Nicole Alicea Plumey
- Raphael Santos
- Mitzael Pitre
