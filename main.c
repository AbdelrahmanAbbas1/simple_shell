#define MAX_COMMAND_SIZE 1024
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - entry point
 *
 * Return: 0 (Success)
 */
int main(void)
{
	char command[MAX_COMMAND_SIZE];
	pid_t child_pid;
	int status;

	while (1)
	{
		printf("simple_shell$ ");
		if (fgets(command, MAX_COMMAND_SIZE, stdin) == NULL)
		{
			printf("\n");
			break;
		}
		command[strcspn(command, "\n")] = '\0';
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork error");
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			int ret = execlp(command, command, NULL);

			perror("Command execution error");
			exit(ret);
		}
		else
		{
			waitpid(child_pid, &status, 0);
			if (WIFEXITED(status))
			{
				printf("Child process exited with statsus %d\n", WEXITSTATUS(status));
			} else if (WIFSIGNALED(status))
			{
				printf("Child process terminated by signal %d\n", WTERMSIG(status));
			}
		}
	}
	return (0);
}
