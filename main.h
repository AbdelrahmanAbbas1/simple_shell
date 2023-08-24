#ifndef MAIN_H

#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <signal.h>

extern char **environ;
int space_det(char *s);
char **split_command(char *command);
void print_error(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
int _strlen(char *s);
void free_args(char **command_args);
char *handle_path(char *command);
void print_env(void);
void wait_print(int *status, char *prompt);
int check_empty(char *command);
#endif
