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
	int old_len = 0;
	int new_len = 0;
	char *path = "/bin/";
	char *tmp;

	if ((_strncmp(command, "/bin/", 5) != 0) &&
			(_strncmp(command, "/usr/bin/", 9) != 0))
	{
		old_len = _strlen(command);
		new_len = old_len + 5 + 1;
		command = realloc(command, sizeof(char) * new_len);
		if (command == NULL)
			return (NULL);

		tmp = malloc(sizeof(char *) * old_len);
		if (tmp == NULL)
			return (NULL);

		for (i = 0; i < old_len; i++)
			tmp[i] = command[i];

		for (i = 0; path[i] != '\0'; i++)
			command[i] = path[i];

		for (; i < new_len - 1; i++)
		{
			command[i] = tmp[k];
			k++;
		}
		command[i] = '\0';
		free(tmp);
	}
	return (command);
}
