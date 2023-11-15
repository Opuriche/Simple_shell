#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LINE 256
/**
 * _getline - implements a custom getline function
 * @in_line: input line
 * @buf_size: buffer size
 * @fd: file descriptor
 * Return: the string
 */

ssize_t _getline(char **in_line, size_t *buf_size, int fd)
{
	char *curr_pos;
	char curr_char;

	if (in_line == NULL || buf_size == NULL)
	{
		return (-1);
	}

	if (*in_line == NULL)
	{
		*buf_size = MAX_LINE;
		*in_line = (char *)malloc(*buf_size);
		if (*in_line == NULL)
		{
			return (-1);
		}
	}

	curr_pos = *in_line;

	while (1)
	{
		ssize_t bytes_read = read(fd, &curr_char, 1);

		if (bytes_read == -1)
		{
			return (-1);
		}

		if (bytes_read == 0 || curr_char == '\n')
		{
			*curr_pos = '\0';
			break;
		}

		*curr_pos = curr_char;
		curr_pos++;

		if ((size_t)(curr_pos - *in_line) >= *buf_size - 1)
		{
			break;
		}
	}

	return ((ssize_t)(curr_pos - *in_line));
}

