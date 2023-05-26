#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
/**
 * struct buildin - Struct build-in commands
 * @cmd: The build in command
 * @func: the function associated
 */

typedef struct buildin
{
	char *cmd;
	int (*func)(char *exe, int ac, char **av, char **e, int s);
} buildin_t;

extern char **environ;
