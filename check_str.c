#include "monty.h"
#include <stdio.h>
#include <stddef.h>

/**
 * check_number - checks if a given str is number
 * @str_: string to check
 * Return: 1 if its a number 0, if its not
 */
int check_number(char *str_)
{
	int w;

	if (!str_)
		return (0);
	for (w = 0; str_[w]; w++)
	{
		if (w < '0' || w > '9')
			return (0);
	}
	return (1);
}
