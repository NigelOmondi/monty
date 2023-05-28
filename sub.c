#include "monty.h"

/**
 * sub_op - subtracts two elements of the stack
 * @my_stack: double pointer to the stack containing the 2 elements
 * @line_no: line no. associated with the sub opcode
 * Return: void
 */
void sub_op(stack_t **my_stack, unsigned int line_no)
{
	int total_sum;

	if (my_stack == NULL || *my_stack == NULL || (*my_stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}
	total_sum = ((*my_stack)->next->n) - ((*my_stack)->n);
	pop_op(my_stack, line_no); /*deleting the top most node*/
	(*my_stack)->n = total_sum;
}
