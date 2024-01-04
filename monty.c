#include "monty.h"
/**
 * main - Entry point
 * @argc: argument count
 * @argv: double pointer to argument vector
 *
 * Return: 0 Success
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	FILE *file = fopen(argv[1], "r");
	stack_t *stack = NULL;

	if (argc != 2 || !(file))
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		char *opcode = strtok(line, " \n\t");
		char *arg = strtok(NULL, " \n\t");

		line_number++;
		if (opcode)
			exe(opcode, &stack, line_number, arg);
	}
	fclose(file);
	free(line);
	while (stack != NULL)
	{
		stack_t *temp = stack;
		stack = stack->next;
		free(temp);
	}
	return (0);
}
