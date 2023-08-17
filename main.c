#include "main.h"

/**
 * main - Entry point
 * @ac: Argument count
 * @av: Argument vector
 * Return: 0 (On success) or -1 otherwise
 */
int main(int ac __attribute__((unused)), char **av)
{
	ssize_t input_count;
	char *command = NULL;
	size_t command_size = 0;
	char *command_args[2];
	pid_t child_pid;
	int status;
	int i;

	printf("#cisfun$ ");
	while ((input_count = getline(&command, &command_size, stdin)) != EOF)
	{
		if (command[input_count - 1] == '\n')
			command[input_count - 1] = '\0';

		command_args[0] = command;
		command_args[1] = NULL;

		child_pid = fork();
		if (child_pid == -1)
		{
			printf("fork ERROR\n");
		}

		else if (child_pid == 0)
		{
			i = execve(command_args[0], command_args, NULL);
			if (i == -1)
			{
				printf("%s: No such file or directory\n", av[0]);
				printf("#cisfun$ ");
			}
		}
		else
		{
			wait(&status);
			printf("#cisfun$ ");
		}
	}
	free(command);
	return (0);
}
