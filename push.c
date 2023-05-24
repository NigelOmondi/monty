#include "monty.h"


/**
 * push - Pushes an element to the top of the stack.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the opcode in the Monty file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *value_str;
	int value;

	value_str = strtok(NULL, DELIMITERS);
	if (value_str == NULL || !is_number(value_str))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	value = atoi(value_str);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
