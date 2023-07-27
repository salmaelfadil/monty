#include "monty.h"
/**
 * _getline - custom implementation of getline
 * @lineptr: line pointer
 * @n: buffer size
 * @stream: sream
 * Return: ssize_t
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream) 
{
size_t pos = 0;
int c;

if (*lineptr == NULL || *n == 0) 
{
*n = 128;
*lineptr = malloc(*n);
if (!*lineptr) 
{
fprintf(stderr, "Memory allocation error\n");
exit(EXIT_FAILURE);
}
}

while (1) 
{
c = fgetc(stream);

if (c == EOF) 
{
if (pos == 0) 
{
return -1;
} 
else 
{
break;
}
}
(*lineptr)[pos++] = c;
if (pos >= *n) 
{
*n *= 2;
*lineptr = realloc(*lineptr, *n);
if (!*lineptr) 
{
fprintf(stderr, "Memory allocation error\n");
exit(EXIT_FAILURE);
}
}
if (c == '\n') 
{
break;
}}
(*lineptr)[pos] = '\0';
return pos;
}
