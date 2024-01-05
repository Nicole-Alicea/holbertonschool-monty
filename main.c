#include "monty.h"

var_t var;

/**
 * file_close - close file stream
 * @status: status passed to exit
 * @arg: pointer to file stream
 *
 * Return: void
 */
void file_close(int status, void *arg)
{
	FILE *file;

	(void)status;

	file = (FILE *) arg;
	fclose(file);
}

/**
 * main - Monty bytecode interpreter
 * @argc: number of arguments passed
 * @argv: array of argument strings
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	FILE *file = NULL;
	char *line = NULL, *op = NULL;
	size_t n = 0;

	var.queue = 0;
	var.stack_len = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	on_exit(free_line, &line);
	on_exit(free_the_stack, &stack);
	on_exit(file_close, file);
	while (getline(&line, &n, file) != -1)
	{
		line_number++;
		op = strtok(line, "\n\t\r ");
		if (op != NULL && op[0] != '#')
		{
			execute(op, &stack, line_number);
		}
	}
	exit(EXIT_SUCCESS);
}
