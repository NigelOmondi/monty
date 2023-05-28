#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"


/**
 * main - code to test the monty program
 * @argv: array of arguments passed to the program
 * @argc: size of arguments(counter)
 * Return: nothin
 */
int main(int argc, char **argv)
{
	int status = 0;
	char *string = NULL;
	stack_t *my_stack = NULL;
	size_t bufferlen = 0;
	FILE *file;
	unsigned int line_no = 1;
	char *buffer = NULL;

	global.data_struct = 1; /*stack*/
	if (argc != 2)
		print_error_usage();

	file = fopen(argv[1], "r");

	if (!file)
		print_file_error(argv[1]);

	while ((getline(&buffer, &bufferlen, file)) != (-1))
	{
		if (status)
			break;
		if (*buffer == '\n')
		{
			line_no++;
			continue;
		}
		string = strtok(buffer, " \t\n");
		if (!string || *string == '#')
		{
			line_no++;
			continue;
		}
		global.argument = strtok(NULL, " \t\n");
		opcode(&my_stack, string, line_no);
		line_no++;
	}
	free(buffer);
	stackfreeing(my_stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}
