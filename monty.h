#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>

extern int check_op;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_num);
} instruction_t;

/**
 * struct data_s - struct containing all data
 * @file: file
 * @check_op: maps function
 * @buffer: buffer
 * Description: struct containg data
 */
typedef struct data_s
{
	FILE *file;
	int check_op;
	char *buffer;
} data_t;

extern data_t data;
char *tokenize(char *line, stack_t **stack, unsigned int line_num);
typedef void (*instruct_func)(stack_t **stack, unsigned int line_num);
instruct_func get_func(char *str);
bool num_check(char *str);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

void pall(stack_t **stack, unsigned int line_num);
void push(stack_t **stack, unsigned int line_num);
void pint(stack_t **stack, unsigned int line_num);
void pop(stack_t **stack, unsigned int line_num);
void swap(stack_t **stack, unsigned int line_num);
void nop(stack_t **stack, unsigned int line_num);
void add(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *head);

#endif
