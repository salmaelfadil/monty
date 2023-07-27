#include "monty.h"
/**
 * copy_toline -- copies data read into pointer
 * @line: pointer that will store input
 * @n: size of line
 * @buf: buffer
 * @size_buf: size of buffer
 * Return: nothing
 */
void copy_toline(char **line, size_t *n, char *buf, size_t size_buf)
{
	if (!(*line))
	{
		if (size_buf > 120)
			*n = size_buf;
		else
			*n = 120;
		*line = buf;
	}
	else if (*n < size_buf)
	{
		if (size_buf > 120)
			*n = size_buf;
		else
			*n = 120;
		*line = buf;
	}
	else
	{
		strcpy(*line, buf);
		free(buf);
	}
}
/**
 * get_line - custom implementtion of getline function
 * @line: line to store
 * @n: size of line
 * @stream: stream
 *
 * Return: number of bytes
 */
ssize_t get_line(char **line, size_t *n, FILE *stream)
{
	static ssize_t args;
	ssize_t val;
	char c = 'z', *buf;
	int bytes_read;

	if (args == 0)
		fflush(stream);
	else
		return (-1);
	args = 0;

	buf = malloc(sizeof(char) * 120);
	if (!buf)
		return (-1);
	while (c != '\n')
	{
		bytes_read = read(STDIN_FILENO, &c, 1);
		if (bytes_read == -1 || (bytes_read == 0 && args == 0))
		{
			free(buf);
			return (-1);
		}
		if (bytes_read == 0 && args != 0)
		{
			args++;
			break;
		}
		if (args >= 120)
			buf = realloc(buf, args + 1);
		buf[args] = c;
		args++;
	}
	buf[args] = '\0';
	copy_toline(line, n, buf, args);
	val = args;
	if (val != 0)
		args = 0;
	return (val);
}
