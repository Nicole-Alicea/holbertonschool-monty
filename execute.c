#include "monty.h"
/**
 * exe - Executes different operations based on the
 * value of the 'opcode' parameter
 * @line: String representing the operation to be performed
 * @stack: Double pointer to a stack data structure
 * @line_number: File's line number
 * @arg: String argument
 * Return: void
 */
int execute(char *content, stack_t **head, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop}, {"swap", swap},
		{"add", add}, {"nop", nop}};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
/**int exe(char *line, char *arg, stack_t **stack, unsigned int line_number,
		FILE *file)
{
	instruction_t opst[] = {{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add}, {"nop", nop}}
	unsigned int x = 0;
	char *op = strtok(line, " \n\t");

	if (op && op[0] == '#')
		return (0);
	arg = strtok(NULL, " \n\t");

	while (opst[x].opcode && op)
	{
		if (strcmp(op, opst[x].opcode) == 0)
		{
			opst[x].f(stack, line_number);
			return (0);
		}
		x++;
	}
	if (op && opst[x].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
		fclose(file);
		free(line);
		free_the_stack(*stack);
		exit(EXIT_FAILURE);
	}
}*/
	/**if (strcmp(line, "push") == 0)
	{
		push(stack, arg, line_number, file, line);
	}
	else if (strcmp(line, "pall") == 0)
	{
		pall(stack, line_number);
	}
	else if (strcmp(line, "pint") == 0)
	{
		pint(stack, line_number);
	}
	else if (strcmp(line, "pop") == 0)
	{
		pop(stack, file, line, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number,
				line);
		exit(EXIT_FAILURE);
	}
	return (1);*/
