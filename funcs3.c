#include "monty.h"
/**
 * push - pushes a value to a stack_t linked list.
 * @top: double pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void push(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
stack_t *new;

new = malloc(sizeof(stack_t));

if (!new)
{
fprintf(stderr, "Memory allocation error\n");
exit(EXIT_FAILURE);
}
new->n = data.check_op;
new->prev = NULL;
new->next = *stack;
if (*stack)
{
(*stack)->prev = new;
}
*stack = new;
}

/**
 * pall - function that prints all elements
 * @stack: double pointer  to linked list stack
 * @line_number: number of line
 * Return: nothin
 */
void pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
stack_t *tmp = *stack;

while (tmp)
{
printf("%d\n", tmp->n);
tmp = tmp->next;
}
}
/**
 * pint - print int a top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line
 * Retutn: noting
 *
 */
void pint(stack_t **stack, unsigned int line_number)
{
stack_t *tmp = *stack;

if (!tmp)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
printf("%d\n", tmp->n);
}
/**
 * pop - delete an element from list
 *@stack: double pointer
 *@line_number: number of line
 *Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
stack_t *tmp = *stack;
if (!stack || *stack == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}
*stack = tmp->next;
if (*stack != NULL)
(*stack)->prev = NULL;
free(tmp);
}

/**
 * free_stack - free stack
 * @head: pointer to head of stack
 * Return: nothing
 */
void free_stack(stack_t *head)
{
stack_t *tmp;
while (head != NULL)
{
tmp = head->next;
free(head);
head = tmp;
}
}
