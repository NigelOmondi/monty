#include "./monty.h"
#include <string.h>
#include <stdlib.h>

/**
 * opcode_ - sets the LIFO AND FIFO FORMAT
 * @my_stack: stack to set format
 * @str: the string to compare with the opcodes
 * @line_no: line associated with the opcodes stack and queue
 * Return: void
 */
void opcode_(stack_t **my_stack, char *str, unsigned int line_no)
{
	int w = 0;
	instruction_t opcodes[] = INSTRUCTIONS;

	if (!strcmp(str, "queue"))
	{
		globalData.mode = 0;
		return;
	}
	if (!strcmp(str, "stack"))
	{
		globalData.mode = 1;
		return;
	}
	while (opcodes[w].opcode)
	{
		if (strcmp(opcodes[w].opcode, str) == 0)
		{
			opcodes[w].f(my_stack, line_no);
			return; /*checking for a match and runnig the program*/
		}
		w++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_no, str);
	exit(EXIT_FAILURE);
}
