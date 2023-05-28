#include "monty.h"

/**
 * mul_op - multiplies two elements of a stack
 * @my_stack: double pointer to the stack containing the 2 elements
 * @line_no: line no. associated with the mul opcode
 * Return: void
 */
void mul_op(stack_t **my_stack, unsigned int line_no)
{
	int product_;

	if (!my_stack || !*my_stack || !((*my_stack)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_no);
		exit(EXIT_FAILURE);
		return;
	}
	product_ = ((*my_stack)->next->n) * ((*my_stack)->n);
	pop_op(my_stack, line_no);
	(*my_stack)->n = product_;
}
