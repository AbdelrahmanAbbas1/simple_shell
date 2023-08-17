#include "main.h"

/**
 * free_args - Frees the memory of a pointer to arrays
 * @command_args: The pointer to array
 */
void free_args(char **command_args)
{
	int i;

	if (command_args == NULL)
		return;

	for (i = 0; command_args[i] != NULL; i++)
	{
		free(command_args[i]);
	}
	free(command_args);
}
