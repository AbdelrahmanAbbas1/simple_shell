#include "main.h"

/**
 * check_empty - Checks if the command is empty or not
 * @command: The command
 * Return: 0 if empty and -1 otherwise
 */
int check_empty(char *command)
{
	int i;
	int checker = 0;

	for (i = 0; command[i] != '\0'; i++)
	{
		if (command[i] == ' ')
			continue;
		checker = 1;
	}
	return (checker);
}
