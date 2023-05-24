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
int main(__attribute__((unsude)) int ac, char **av)
{
	int i, len = 0, status = 0;
	char **e = environ, **command = NULL;
	char *buffLine = NULL, *buffLinecpy = NULL, **args = NULL;
	size_t length;
	ssize_t totalchar = 0;
	int (*func)(char *x, int ac, char **args, char ***ptenv, int status)

	while (1)
	{
		write(1, "little_shell:)", 14);
		totalchar = getline(&buffLine, &length, stdin);
		if (totalchar == -1)
		{
			free(buffLine);
			printf("exiting little shell\n");
			return (-1);
		}
		command = getAllCmd(buffLinecpy);
		for (i = 0; command[i] != NULL; i++)
		{
			args = splitecmd(command[i], e, status);
			len = getArLen(args);
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
					status = exetcmd(av[0], args, e);
			}
			freeargs(args);
		}
		freeargs(command);

	}
	free(buffLine), return (0);
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

