#include "monty.h"
/**
 * push - push a new int to the stack
 * @stack: stack
 * @line_num: line number
 * Return: nothing
 */
void push(stack_t **stack, __attribute__ ((unused))unsigned int line_num)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = data.check_op;
	new->next = *stack;
	new->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}
/**
 * pint - print the top element
 * @stack: double pointer
 * @line_num: line number
 * Return: nothing
 *
 */
void pint(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	tmp = *stack;
	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", tmp->n);
}
/**
 * pop - remove element
 *@stack: double opinter
 *@line_num: number of line
 *Return: nothing
 */
void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
/**
 * free_stack - free a list
 * @head: pointer to head
 * Return: nothing
 */
void free_stack(stack_t *head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
