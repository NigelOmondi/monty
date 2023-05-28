#include "monty.h"

/**
 * nop_op - implements the nop opcode, nop doesnt do anything
 * @my_stack: Double pointer to the stack to not do anything on
 * @line_no: line no. associated with the nop opcode
 * Return: void
 */
void nop_op(stack_t **my_stack, unsigned int line_no)
{
	(void) my_stack;
	(void) line_no;
}
