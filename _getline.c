#include "shell.h"

/**
 * _getline - implements a custom getline function
 * @buf_size: buffer size
 * @buffer: the buffer
 * Return: the result
 */

#define MAX_LEN 1000
#define MAX_ARGS 100

ssize_t _getline(char *buffer, size_t buf_size)
{
	static char in_buf[MAX_LEN];
	static size_t buf_idx;
	static ssize_t bytes_read;
	size_t j;

	if (buf_idx == 0)
	{
		bytes_read = read(STDIN_FILENO, in_buf, MAX_LEN);
		if (bytes_read <= 0)
		{
			return (-1);
		}
	}

	for (j = 0; j < buf_size - 1 && buf_idx < (size_t)bytes_read; j++, buf_idx++)
	{
		if (in_buf[buf_idx] == '\n')
		{
			buffer[j] = '\0';
			buf_idx++;
			return (j + 1);
		}
		buffer[j] = in_buf[buf_idx];
	}

	buffer[j] = '\0';

	return (j);
}

/**
 * tfer_input - tokenizes input to arguments
 * @input: input
 * @args: arguments
 * Return: the count
 */

int tfer_input(char *input, char *args[])
{
	int argcnt = 0;
	char *token = strtok(input, " \t\n");

	while (token != NULL && argcnt < MAX_ARGS - 1)
	{
		args[argcnt] = token;
		argcnt++;
		token = strtok(NULL, " \t\n");
	}

	args[argcnt] = NULL;

	return (argcnt);
}
