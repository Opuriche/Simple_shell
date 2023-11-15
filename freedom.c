#include "shell.h"

/**
 * freedom - frees allocated memory
 * @args: argument
 * Return: void
 */

void freedom(char **args)
{
	free(args);
	exit(EXIT_SUCCESS);
}
