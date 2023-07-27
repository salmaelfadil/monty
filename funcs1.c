#include "monty.h"
/**
 * tokenize_line -- tokenizes line
 * @line: line to be tokenized
 * @stack: double pointer to head of stack
 * @line_num: line number
 * Return: returns tokenized line
*/
char *tokenize_line(char *line, stack_t **stack,
		unsigned int line_num)
{
	char *token, *args;
	int i = 0;
	bool int_flag;
	(void) stack;

	token = strtok(line, "\n ");

	if (!token)
		return (NULL);
	if (strcmp(token, "push") == 0)
	{
		args = strtok(NULL, "\n");
		int_flag = num_check(args);
		if (int_flag == true && args != NULL)
			data.check_op = atoi(args);
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
	}
	return (token);
}
/**
 * num_check - checks if string is a number
 * @str: string
 * Return: True if number
 */
bool num_check(char *str)
{
	int i = 0;

	if (!str)
		return (false);
	for(; str[i]; i++)
	{
		if (str[0] == '-')
			i++;
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}
/**
 * get_func -- maps the correct function
 * @str: string
 * Return: returns function
 */
instruct_func get_func(char *str)
{
	int i = 0;

	instruction_t instruct[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{NULL, NULL},
	};
	for (; instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0; i++)
	{
		;
	}
	return (instruct[i].f);
}
