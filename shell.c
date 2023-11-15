#include "shell.h"

/**
 * main - a simple shell
 * @argc: argument count
 * @argv: argument vector
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	char buffer[BUFFER_SIZE];
	pid_t child_pid;
	int status;
	int i;

	while (1)
	{
		ssize_t bytes = _input(buffer, BUFFER_SIZE);

		if (bytes == -1)
		{
			perror("input error");
			exit(EXIT_FAILURE);
		}

		if (bytes == 0)
		{
			write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}

		buffer[bytes - 1] = '\0';

		child_pid = fork();

		if (child_pid == -1)
		{
			perror("child process error");
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0)
		{
			char **args = malloc((argc + 1) * sizeof(char *));

			if (args == NULL)
			{
				perror("memory allocation fault");
				exit(EXIT_FAILURE);
			}

			for (i = 0; i < argc; i++)
			{
				args[i] = argv[i];
			}
			args[argc] = NULL;

			execute(buffer, args);
			freedom(args);
		}

		else
		{
			if (waitpid(child_pid, &status, 0) == -1)
			{
				perror("child process error");
				exit(EXIT_FAILURE);
			}
		}
	}

	return (0);
}

