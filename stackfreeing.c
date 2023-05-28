#include "monty.h"

/**
 * stackfreeing - used to free the stack (linked list)
 * @my_stack: pointer to the stack to free
 * Return: void
 */
void stackfreeing(stack_t *my_stack)
{
	stack_t *presentnode = my_stack;
	stack_t *nextnode;

	if (my_stack)
	{
		nextnode = my_stack->next;
		while (presentnode)
		{
			free(presentnode);
			presentnode = nextnode;
			if (nextnode)
				nextnode = nextnode->next;
		}
	}
}

