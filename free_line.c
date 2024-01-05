#include "monty.h"

/**
 * free_line - free line pointer returned by getline
 * @status: exit status
 * @arg: pointer to line
 *
 * Return: void
 */
void free_line(int status, void *arg)
{
	char **line = arg;

	(void)status;
	if (*line != NULL)
	{
		free(*line);
	}
}
