#include "monty.h"
/**
 * tokenize - tokenizes line
 * @line: line
 * @stack: double pointer
 * @line_num: line num
 * Return: string
 */
char *tokenize(char *line, __attribute__ ((unused))stack_t **stack,
	       	unsigned int line_num)
{
	char *token;
	char *str;

	token = strtok(line, "\n ");
	if (!token)
		return (NULL);

	if (strcmp(token, "push") == 0)
	{
		str = strtok(NULL, "\n ");
		if (num_check(str) == 1 && str != NULL)
			data.check_op = atoi(str);
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
	}
	return (token);
}
