#include "monty.h"
/**
 * main - main entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char **argv)
{
	stack_t *stack;
	char *line;
	instruct_func func;
	size_t n = 0;
	int num = 1;

	stack = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	data.file = fopen(argv[1], "r");
	if (data.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&data.buffer, &n, data.file) != -1)
	{
		line = tokenize(data.buffer, &stack, num);
		if (line == NULL || line[0] == '#')
		{
			num++;
			continue;
		}
		func = get_func(line);
		if (func == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", num, line);
			exit(EXIT_FAILURE);
		}
		func(&stack, num);
		num++;
	}
	free(data.buffer);
	if (fclose(data.file) == -1)
		exit(-1);
	free_stack(stack);
	return (0);
}
