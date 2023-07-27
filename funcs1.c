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
	bool int_flag = false;

	token = strtok(line, "\n ");

	if (!token)
		return (NULL);
	if (strcmp(token, "push") == 0)
	{
		args = strtok(NULL, "\n");
		while (args[i])
		{
			if (args[0] == '-')
			{
				i++;
				continue;
			}
			if (!isdigit(args[i]))
			{
				int_flag = false;
			}
			i++;
			int_flag = true;
		}
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
