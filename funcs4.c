#include "monty.h"
/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer
 * @line_num: number of line
 * Return: nothing
 */

void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;
	int i;

	tmp = *stack;
	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	i = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = i;
}
/**
 * add - adds top two elements of stack
 * @stack: double pointer
 * @line_num: line num
 * Return: nothing
 */

void add(stack_t **stack, unsigned int line_num)
{
	stack_t *node = *stack;
	int add = 0, i = 0;

	if (!node)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	for (; node; i++)
	{
		node = node->next;
	}

	if (stack == NULL || (*stack)->next == NULL || i <= 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	add = (*stack)->next->n + (*stack)->n;
	pop(stack, line_num);

	(*stack)->n = add;
}
/**
 * nop - nop top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_num: number of line opcode occurs on
 */

void nop(__attribute__ ((unused))stack_t **stack,
		__attribute__ ((unused)) unsigned int line_num)
{
	;
}

