#include "monty.h"
#include <stdio.h>
#include "monty.h"

/**
 * pchar_op - prints the char at the top of the stack
 * @my_stack: double pointer to the stack with char to print
 * @line_no: line no associated with the opcode pchar
 * Return: void
 */
void pchar_op(stack_t **my_stack, unsigned int line_no)
{
	if (!my_stack || !(*my_stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_no);
		exit(EXIT_FAILURE);
		return;
	}
	if ((*my_stack)->n < 0 || (*my_stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_no);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%c\n", (*my_stack)->n);
}
