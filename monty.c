#include "monty.h"

#include "monty.h"

/**
 * main - Monty bytecode interpreter
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *bytecode_file;
	char *line = NULL;
	size_t line_buf_size = 0;
	ssize_t line_size;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	bytecode_file = fopen(argv[1], "r");
	if (!bytecode_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((line_size = getline(&line, &line_buf_size, bytecode_file)) != -1)
	{
		line_number++;
		if (line_size > 0 && line[line_size - 1] == '\n')
			line[line_size - 1] = '\0';

		if (line[0] != '\0')
		{
			char *opcode = strtok(line, " \t");
			char *arg = strtok(NULL, " \t");

			if (opcode)
				execute_instruction(&stack, opcode, arg, line_number);
		}
	}

	free(line);
	free_stack(stack);
	fclose(bytecode_file);
	exit(EXIT_SUCCESS);
}

/**
 * execute_instruction - Executes the opcode instruction
 * @stack: Double pointer to the stack
 * @opcode: The opcode to execute
 * @arg: The argument for the opcode
 * @line_number: The current line number in the bytecode file
 */
void execute_instruction(stack_t **stack, char *opcode,
		char *arg, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	int i = 0;

	while (instructions[i].opcode)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			instructions[i].f(stack, line_number, arg);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}

/**
 * push - Pushes an element to the stack
 * @stack: Double pointer to the stack
 * @line_number: The current line number in the bytecode file
 * @arg: The argument for the push opcode
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
	stack_t *new_node;

	if (!arg || !is_integer(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(arg);
	new_node->prev = NULL;

	if (*stack)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	else
		new_node->next = NULL;

	*stack = new_node;
}
