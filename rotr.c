#include "monty.h"

/**
 * rotr_op - the last element of the stack becomes the top of the stack
 * @my_stack: the stack to rotate
 * @line_no: line associated with the opcode
 * Return: void
 */
void rotr_op(stack_t **my_stack, unsigned int line_no __attribute__((unused)))
{

	stack_t *bottom;
	stack_t *previous;

	if (my_stack == NULL || *my_stack == NULL || (*my_stack)->next == NULL)
		return;
	bottom = *my_stack;

	while (bottom->next)
		bottom = bottom->next;
	previous = bottom->prev;
	bottom->next = *my_stack;
	bottom->prev = NULL;
	previous->next = NULL;
	(*my_stack)->prev = bottom;
	*my_stack = bottom;
}
