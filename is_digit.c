#include "monty.h"

/**
 * is_digit - checks whether the string contains digits
 * @str: the string to check
 * Return: 0 if not digit, 1 if digit
 */
int is_digit(char *str)
{
	if (!str || *str == '\0')
		return (0);
	if (*str == '-')
		str++;
	while (*str)
	{
		if (isdigit(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}
