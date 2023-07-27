#include "monty.h"
/**
 * swap - swaps the top two elements of the stack.
 * @stack: double pointer
 * @line_number: number of line
 * Retutn: nothin
 */

void swap(stack_t **stack, unsigned int line_number)
{
stack_t *tmp = *stack;
int i;

tmp = *stack;
if (!tmp || tmp->next == NULL)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
i = tmp->n;
tmp->n = tmp->next->n;
tmp->next->n = i;
}

/**
 * add - adds the top two elements of the stack.
 * @stack: double pointer
 * @line_number: number of line
 * Return: nothing
 */

void add(stack_t **stack, unsigned int line_number)
{
stack_t *temp = *stack;
int sum = 0, i = 0;

if (!temp)
{
fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

for (; temp != NULL; i++)
{
temp = temp->next;
}
if (!stack || (*stack)->next == NULL || i <= 1)
{
fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
sum = (*stack)->next->n + (*stack)->n;
pop(stack, line_number);

(*stack)->n = sum;
}

/**
 * nop - does not do anything
 * @stack: double pointer
 * @line_number: number of line
 * Return: nothing
 */
void nop(__attribute__ ((unused))stack_t **stack,
		__attribute__ ((unused)) unsigned int line_number)
{
;
}
