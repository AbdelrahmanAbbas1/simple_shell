#include "main.h"

/**
 * handle_path - Handle the PATH variable
 * @command: The command to be entered
 *
 * Return: A pointer to the new path of the command
 */
char *handle_path(char *command)
{
	int i, k = 0;
	char *path = "/bin/";
	char *command_path;

	if ((_strncmp(command, "/bin/", 5) != 0) &&
			(_strncmp(command, "/usr/bin/", 9) != 0))
	{
		command_path = malloc(sizeof(char) * (5 + _strlen(command) + 1));
		if (command_path == NULL)
			return (NULL);

		for (i = 0; path[i] != '\0'; i++)
			command_path[i] = path[i];

		for (k = 0; command[k] != '\0'; k++)
		{
			command_path[i] = command[k];
			i++;
		}
		command_path[i] = '\0';
		return (command_path);
	}
	return (command);
}
