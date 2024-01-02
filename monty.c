#include "monty.h"

stack_t *stack = NULL;

int main(void)
{
	char opcode[256];
	int value;
	unsigned int line_number = 0;
	FILE *file = fopen("your_input_file.txt", "r");

	if (file == NULL)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}

	while (fscanf(file, "%s", opcode) != EOF)
	{
		line_number++;

		if (strcmp(opcode, "push") == 0)
		{
			if (fscanf(file, "%d", &value) != 1)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			push(&stack, value, line_number);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%d: Unknown opcode: %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
	fclose(file);
	return (0);
}
