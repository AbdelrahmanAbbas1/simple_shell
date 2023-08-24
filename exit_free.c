#include "main.h"

/**
 * exit_free - Frees the memory and exit from the program
 * @command: The command to be freed
 * @command_args: The command to be freed
 * @file_name: The name of the file which cannot be located
 */
void exit_free(char *command, char **command_args, char *file_name)
{
	free(command);
	free(command_args);
	printf("%s: No such file or directory\n", file_name);
	exit(99);
}
