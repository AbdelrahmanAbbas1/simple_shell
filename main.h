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
#endif
