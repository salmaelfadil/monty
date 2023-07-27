#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

extern int check_op;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
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
 * struct data_var_s - opcoode and its function
 * @file: the file
 * @check_op: function to get opcode
 * @buffer: buffer
 * Description: global variable that stores all info
 */
typedef struct data_var_s
{
	FILE *file;
	int check_op;
	char *buffer;
} data_var_t;

extern data_var_t data;

typedef void (*instruct_func)(stack_t **stack, unsigned int line_number);
instruct_func get_func(char *str);

char *tokenize_line(char *line, stack_t **stack, unsigned int line_num);

void push(stack_t **stack, __attribute__ ((unused))unsigned int line_number);
void pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *head);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
#endif
