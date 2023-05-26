#include "shel.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/**
 * main - function main
 * @ac: number of arg
 * @av: array
 * Return: 0
 */
int main(__attribute__((unused)) int ac, char **av)
{
	int i, len = 0, status = 0;
	char **e = environ, **command = NULL;
	char *buffLine = NULL, **args = NULL;
	size_t length;
	ssize_t totalchar = 0;
	int (*func)(char *x, int ac, char **args, char **ptenv, int status);

	signal(SIGINT, prtsignal);
	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, "little_shell ->  ", 17);
		totalchar = getline(&buffLine, &length, stdin);
		if (totalchar < 0)
		{
			free(buffLine);
			return (-1);
		}
		command = getAllCmd(buffLine);
		for (i = 0; command[i] != NULL; i++)
		{
			args = splitline(command[i], e, status);
			len = getArlen(args);
			if (len > 0)
			{
				func = callMyFunc(args[0]);
				if (func)
				{
					status = func(av[0], len, args, e, status);
					if (status != 0)
						exitcmd(status, args, buffLine, command);
				}
				else
					status = exectcmd(av[0], args, e);
			}
			freeit(args);
		}
		freeit(command);
	}
	return (0);
}
/**
 * getArlen - get length of array of pointers
 * @args: pointer of pointer to arguments
 * Return: number of args
 */
int getArlen(char **args)
{
	int n = 0;

	while (args)
	{
		n++;
		args++;
	}
	return (n);
}
/**
 * exitcmd - exit command
 * @status: exit status
 * @av: array of arguments
 * @line: line
 * @c: command
 */
void exitcmd(int status, char **av, char *line, char **c)
{
	freeit(av);
	free(line);
	freeit(c);
	if (status == 200)
		exit(0);
	exit(status);
}
