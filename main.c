#include "monty.h"
/**
 * main - Entry point
 * @argc: argument count
 * @argv: double pointer to argument vector
 * Return: 0 Success
 */
var_t var;
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	FILE *file = fopen(argv[1], "r");
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		exe(line, NULL, &stack, line_number, file);
		free(line);
		line = NULL;
	}
	free_the_stack(stack);
	fclose(file);
	return (0);
}
