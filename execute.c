#include "shell.h"

/**
 * execute - uses execve in the child process
 * @str: first argument
 * @argv: argument vector
 * Return: the result
 */

void execute(char *str, char *argv[])
{
	char *env[] = {NULL};

	if (execve(str, argv, env) == -1)
	{
		perror("Error executing command");
		exit(EXIT_FAILURE);
	}
}
