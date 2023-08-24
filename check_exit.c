#include "main.h"

/**
 * check_exit - exit with a certain status and frees the command
 * @command: The command to be freed
 * @command_args: Checks if there is command or not
 *
 * Return: The status or 2 otherwise
 */
int check_exit(char *command, char **command_args)
{
	int status = 0;

	free(command);
	if (command_args == NULL)
		return (status);
	return (2);
}
