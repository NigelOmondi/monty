#include "monty.h"

/**
 * enqueue_ - add node on the queue
 * @my_stack: double pointer to the stack to add onto
 * @n: the value/data to add on the newnode/stack
 * Return: newnode if success, NULL if failure
 */
stack_t *enqueue_(stack_t **my_stack, const int n)
{
	stack_t *newnode = malloc(sizeof(stack_t));
	stack_t *presentnode = *my_stack;

	if (!newnode)
	{
		free(newnode);
		return (NULL);
	}
	newnode->n = n;

	if (!*my_stack)
	{
		newnode->next = NULL;
		newnode->prev = NULL;
		*my_stack = newnode;
		return (newnode);
	}
	while (presentnode)
	{
		if (!presentnode->next)
		{
			newnode->next = NULL;
			newnode->prev = presentnode;
			presentnode->next = newnode;
			break;
		}
		presentnode = presentnode->next;
	}
	return (newnode);
}
