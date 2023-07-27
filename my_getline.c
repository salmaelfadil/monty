#include "monty.h"
/**
 * _getline - custom implementation of getline function
 * @line: pointer to store input
 * @n: size of buffer
 * @stream: stream to read from
 *
 * Return: number of bytes read
 */
ssize_t _getline(char **line, size_t *n, FILE *stream)
{
	static size_t args;
	ssize_t val;
	char c = 'x', *buffer;
	int i;

	if (args == 0)
		fflush(stream);
	else
		return (-1);
	args = 0;
	buffer = malloc(sizeof(char) * 120);
	if (!buffer)
		return (-1);

	while (c != '\n')
	{
		i = read(STDIN_FILENO, &c, 1);
		if (i == -1 || (i == 0 && args == 0))
		{
			free(buffer);
			return (-1);
		}
		if (i == 0 && args != 0)
		{
			args++;
			break;
		}
		if (args >= 120)
			buffer = realloc(buffer, args + 1);
		buffer[args] = c;
		args++;
	}
	buffer[args] = '\0';
	if (*line == NULL)
	{
		if (args > 120)
			*n = args;
		else
			*n = 120;
		*line = buffer;
	}
	else if (*n < args)
	{
		if (args > 120)
			*n = args;
		else
			*n = 120;
		*line = buffer;
	}
	else
	{
		strcpy(*line, buffer);
		free(buffer);
	}
	val = args;
	if (i != 0)
	{
		args = 0;
	}
	return (val);
}
