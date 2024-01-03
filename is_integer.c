#include "monty.h"
/**
 * is_integer - ...
 * @arg: ...
 *
 * Return: ...
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
