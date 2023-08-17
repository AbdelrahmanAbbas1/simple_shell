#include "main.h"

/**
 * split_command - Return an array with the command and command arguments
 * @command: The command to be checked
 *
 * Return: Return an a pointer to an array command and args or NULL otherwise
 */
char **split_command(char *command)
{
	int i, arg = 0;
	char *token;
	char **command_args;

	i = space_det(command);
	if (i == -1)
	{
		return (NULL);
	}
	command_args = malloc(sizeof(char *) * (i + 2));
	if (command_args == NULL)
		return (NULL);

	token = strtok(command, " ");
	while (token)
	{
		command_args[arg] = token;
		token = strtok(NULL, " ");
		arg++;
	}
	command_args[arg] = NULL;

	return (command_args);
}
