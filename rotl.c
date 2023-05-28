#include "monty.h"

/**
 * rotl_op - top element becomes the last one, and 2nd top become first one
 * @my_stack: the stack to rotate the elements
 * @line_no: line no associated with the opcode
 * Return: void
 */
void rotl_op(stack_t **my_stack, unsigned int line_no)
{
	stack_t *top;
	stack_t *bottom;

	(void) line_no;
	if (!my_stack || !*my_stack || !(*my_stack)->next)
		return;
	bottom = top = *my_stack;

	while (top->next)
		top = top->next;
	top->next = bottom;
	bottom->prev = top;
	*my_stack = bottom->next;
	(*my_stack)->prev->next = NULL;
	(*my_stack)->prev = NULL;
}
