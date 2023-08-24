#include "main.h"

/**
 * print_env - Print the current environment
 * @command: THe command
 *
 * Return: 0 if comamnd equal to env and -1 otherwise
 */
int print_env(char *command)
{
	int i;

	if (_strcmp(command, "env") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
			printf("%s\n", environ[i]);
		return (0);
	}
	return (-1);
}
