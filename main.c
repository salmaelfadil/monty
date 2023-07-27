#include "monty.h"
/**
 * main - main entry point
 * @argv: arguments vector
 * @argc: arguments count
 * Return: 0 on success
*/
int main(int argc, char **argv)
{
	char *line = NULL;
	stack_t *stack = NULL;
	size_t *buffer_size = 0;
	int line_num = 1;
	instruct_func func;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	data.file = fopen(argv[1], "r");
	if (!data.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (_getline(&data.buffer, buffer_size, data.file) != -1)
	{
		line = tokenize_line(data.buffer, &stack, line_num);
		if (line == NULL || line[0] == '#')
		{
			line_num++;
			continue;
		}
		func = get_func(line);
		if (!func)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, line);
			exit(EXIT_FAILURE);
		}
		func(&stack, line_num);
		line_num++;
	}
	free(data.buffer);
	if (fclose(data.file) == -1)
		exit(-1);
	free_stack(stack);
	exit(EXIT_SUCCESS);
	return (0);
}

