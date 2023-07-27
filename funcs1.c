#include "monty.h"
/**
 * get_func -  maps opcode to right function
 * @str: opcode
 * Return: returns a func to be executed
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
		{"nop", nop},
		{NULL, NULL},
	};
	for (; instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0; i++)
	{
		;
	}
	return (instruct[i].f);
}
/**
 * num_check - checks if a string is a number
 * @str: string
 * Return: returns true if number
 */
bool num_check(char *str)
{
	int i = 0;

	if (!str)
		return (false);
	for (; str[i]; i++)
	{
		if (str[0] == '-')
			continue;
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}
