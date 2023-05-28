#include "monty.h"

/**
 * swap_op - swaps two elements of a stack
 * @my_stack: double pointer containing the elements to wap
 * @line_no: line no. associated with the swap opcode
 * Return: void
 */
void swap_op(stack_t **my_stack, unsigned int line_no)
{
	stack_t *temp_node = NULL;
	int data_var = 0;

	if (!my_stack || !*my_stack || !((*my_stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}

	temp_node = *my_stack;
	data_var = temp_node->n;
	temp_node->n = data_var;

	temp_node->n = temp_node->next->n;
	temp_node->next->n = data_var;
}
