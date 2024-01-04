#include "monty.h"

/**
 * is_integer - Examines the provided string to determine
 * whether it is a valid integer
 * @arg: Input string to be checked
 *
 * Return: 1 if the input string is a valid integer, otherwise 0
 */

int is_integer(const char *arg)
{
	if (arg == NULL)
	{
		return (0);
	}
	if (*arg == '-' || *arg == '+')
	{
		arg++;
	}
	while (*arg)
	{
		if (!isdigit(*arg))
		{
			return (0);
		}
		arg++;
	}
	return (1);
}
