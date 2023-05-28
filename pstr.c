#include "monty.h"

/**
 * pstr_op - prints the string on top of the stack
 * @my_stack: double pointer to print the string from
 * @line_no: line no. associated with the opcode
 * Return: void
 */
void pstr_op(stack_t **my_stack, unsigned int line_no __attribute__((unused)))
{
	stack_t *temp = *my_stack;

	while (temp)
	{
		if (temp->n <= 0 || temp->n > 127)
			break;
		putchar((char) temp->n);
		temp = temp->next;
	}
	putchar('\n');
}
