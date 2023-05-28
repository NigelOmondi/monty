#include "monty.h"

/**
 * push_op - pushes an element on the stack
 * @my_stack: double pointer to the stack
 * @line_no: the line number, visibility of errors
 * Return: void
 */
void push_op(stack_t **my_stack, unsigned int line_no)
{
	char *f = globalData.arg;

	if ((is_digit(f)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_no);
		exit(EXIT_FAILURE);
	}
	if (globalData.mode == 1) /*1 for stack ,0 for queue*/
	{
		if (!nodeadd(my_stack, atoi(globalData.arg)))
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!enqueue_(my_stack, atoi(globalData.arg)))
		{
			exit(EXIT_FAILURE);
		}
	}
}
