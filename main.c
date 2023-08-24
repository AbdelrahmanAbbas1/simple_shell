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
	char **command_args;
	pid_t child_pid;
	int status, i, check_space, check_env;

	while ((input_count = getline(&command, &command_size, stdin)) != EOF)
	{
		if (command[input_count - 1] == '\n')
			command[input_count - 1] = '\0';
		check_env = print_env(command);
		check_space = check_empty(command);
		if (check_space == 0 || check_env == 0)
			continue;
		if (_strcmp(command, "exit") == 0)
			exit(98);
		command_args = split_command(command);
		child_pid = fork();
		if (child_pid == -1)
			return (-1);
		else if (child_pid == 0)
		{
			i = execve(command_args[0], command_args, environ);
			if (i == -1)
			{
				free(command);
				free(command_args);
				printf("%s: No such file or directory\n", av[0]);
				_exit(99);
			}
		}
		else
		{
			wait(&status);
			free(command_args);
		}
	}
	free(command);
	return (0);
}
