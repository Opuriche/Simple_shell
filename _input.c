#include "shell.h"

/**
 * _input - get user input
 * @buffer: Buffer to store input
 * @_size: Size of the buffer
 * Return: bytes read
 */

ssize_t _input(char *buffer, size_t _size)
{
	write(STDOUT_FILENO, "#cisfun$ ", 9);
	return (read(STDIN_FILENO, buffer, _size));
}

