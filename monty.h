#ifndef MONTY_H
#define MONTY_H

#include <string.h>

#include <fcntl.h>
#include <ctype.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>

#define INSTRUCTIONS \
{ \
	{"push", push_op}, \
	{"pall", pall_op}, \
	{"pint", pint_op}, \
	{"pop", pop_op}, \
	{"rotr", rotr_op}, \
	{"swap", swap_op}, \
	{"rotl", rotl_op}, \
	{"nop", nop_op}, \
	{"pstr", pstr_op}, \
	{"div", div_op}, \
	{"pchar", pchar_op}, \
	{"mul", mul_op}, \
	{"mod", mod_op}, \
	{"add", add_op}, \
	{"sub", sub_op}, \
	{NULL, NULL} \
}


/**
 * struct stack_s - doubly linked list representaton of stack(or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct OpcodeArgument - arguments of the current opcode
 * @mode: mode of the opcode, indicating stack mode or queue
 * @arg: argument associated with the opcode string
 *
 * Description: Global structure used to pass data btn function conveniently
 */
typedef struct OpcodeArgument
{
	int mode;
	char *arg;
} OpcodeArgument;
OpcodeArgument globalData;

/* prototypes */
void rotr_op(stack_t **my_stack, unsigned int line_no);
void add_op(stack_t **my_stack, unsigned int line_no);
void push_op(stack_t **my_stack, unsigned int line_no);
void pall_op(stack_t **my_stack, unsigned int line_no);
void pint_op(stack_t **my_stack, unsigned int line_no);
void swap_op(stack_t **my_stack, unsigned int line_no);
void pop_op(stack_t **my_stack, unsigned int line_no);
void nop_op(stack_t **my_stack, unsigned int line_no);
void div_op(stack_t **my_stack, unsigned int line_no);
void sub_op(stack_t **my_stack, unsigned int line_no);
void mul_op(stack_t **my_stack, unsigned int line_no);
void mod_op(stack_t **my_stack, unsigned int line_no);
void pstr_op(stack_t **my_stack, unsigned int line_no);
void pchar_op(stack_t **mystack, unsigned int line_no);
void rotl_op(stack_t **my_stack, unsigned int line_no);
stack_t *nodeadd(stack_t **my_stack, const int n);
stack_t *enqueue_(stack_t **my_stack, const int n);
void opcode_(stack_t **my_stack, char *str, unsigned int line_no);
int is_digit(char *str);
int check_number(char *str_);
void stackfreeing(stack_t *my_stack);
size_t stack_display(const stack_t *my_stack);
void print_file_error(char *argv);
void print_error_usage(void);

#endif /*MONTY_H */
