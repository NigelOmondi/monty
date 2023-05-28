#include "monty.h"

/**
 * nodeadd - adds a node on a stack
 * @my_stack: double pointer to the stack to add the node onto
 * @n: the value/data to push on the stack
 * Return: the new node(success), NULL if it fails
 */
stack_t *nodeadd(stack_t **my_stack, const int n)
{
	stack_t *newnode = malloc(sizeof(stack_t));

	if (!newnode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(newnode);
		return (NULL);
	}
	newnode->n = n;

	newnode->next = *my_stack;
	newnode->prev = NULL;
	if (*my_stack)
		(*my_stack)->prev = newnode;
	*my_stack = newnode;

	return (newnode);
}
