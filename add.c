#include "monty.h"

/**
 * add_op - add the top two elements of the stack
 * @my_stack: double pointer to the stack containing the two elements
 * @line_no: line associated with the add opcode
 * Return: void
 */
void add_op(stack_t **my_stack, unsigned int line_no)
{
	int total_sum;

	if (!my_stack || !*my_stack || !((*my_stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}
	total_sum = ((*my_stack)->next->n) + ((*my_stack)->n);
	pop_op(my_stack, line_no); /*deletes the top*/
	(*my_stack)->n = total_sum;
}
